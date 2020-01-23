#include <iostream>
#include "Song.h"
#include "PlayableFactory.h"
#include "TagSplitter.h"
#include "CorruptContentException.h"
#include "MissingMetadataException.h"
#include "PlayableWithContent.h"

bool Song::isRegistered = PlayableFactory::registerPlayableType(Song::factoryName(), Song::createType);

std::string Song::type() {
    return "Song";
}

std::string Song::header() {
    return artist + ", " + title;
}

Song::Song(const TagSplitter::tagMap &description, const std::string &content)
: PlayableWithContent(description, content) {
    if (!std::regex_match(content, TagSplitter::ALLOWED_CONTENT_REGEX()))
        throw CorruptContentException();

    if (playableTags.count("title"))
        title = playableTags["title"];
    else
        throw MissingMetaDataException("title");

    if (playableTags.count("artist"))
        artist = playableTags["artist"];
    else
        throw MissingMetaDataException("artist");
}
