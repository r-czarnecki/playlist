#include <iostream>
#include "Movie.h"
#include "PlayableFactory.h"
#include "TagSplitter.h"
#include "CorruptContentException.h"
#include "MissingMetadataException.h"

bool Movie::isRegistered = PlayableFactory::registerPlayableType(Movie::factoryName(), Movie::createType);

std::string Movie::type() {
    return "Movie";
}

std::string Movie::header() {
    std::stringstream ss;
    ss << title;
    ss << ", ";
    ss << year;

    return ss.str();
}

std::string Movie::description() {
    return displayText;
}

Movie::Movie(const std::string &description)
: Playable(description, true)
, displayText(TagSplitter::decodeROT13(TagSplitter::getContent(description))) {
    if (!std::regex_match(displayText, TagSplitter::ALLOWED_CONTENT_REGEX()))
        throw CorruptContentException();

    if (playableTags.count("title"))
        title = playableTags["title"];
    else
        throw MissingMetaDataException("title");

    if (playableTags.count("year"))
        year = TagSplitter::PARSE_NUMERIC_TAG(playableTags["year"]);
    else
        throw MissingMetaDataException("year");
}
