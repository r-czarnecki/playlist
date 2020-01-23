#include <iostream>
#include "Movie.h"
#include "PlayableFactory.h"
#include "TagSplitter.h"
#include "CorruptContentException.h"
#include "MissingMetadataException.h"
#include "CorruptYearMetadataException.h"

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

Movie::Movie(const TagSplitter::tagMap &description, const std::string &content)
: PlayableWithContent(description, TagSplitter::decodeROT13(content)) {
    if (!std::regex_match(content, TagSplitter::ALLOWED_CONTENT_REGEX()))
        throw CorruptContentException();

    if (playableTags.count("title"))
        title = playableTags["title"];
    else
        throw MissingMetaDataException("title");

    if (playableTags.count("year")) {
        year = TagSplitter::PARSE_NUMERIC_TAG(playableTags["year"]);

        // Rok zerowy lub ujemny jest niedozwolony
        if (year <= 0)
            throw CorruptYearMetadataException();
    }
    else
        throw MissingMetaDataException("year");
}
