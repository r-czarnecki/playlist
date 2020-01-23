#include <iostream>
#include "Song.h"
#include "PlayableFactory.h"
#include "TagSplitter.h"
#include "CorruptContentException.h"
#include "MissingMetadataException.h"

bool Song::isRegistered = PlayableFactory::registerPlayableType(Song::factoryName(), Song::createType);

std::string Song::type() {
    return "Song";
}

std::string Song::header() {
    return artist + ", " + title;
}

std::string Song::description() {
    return lyrics;
}

Song::Song(const std::string &description)
: Playable(description, true)
, lyrics(TagSplitter::getContent(description)) {
    if (!std::regex_match(lyrics, TagSplitter::ALLOWED_CONTENT_REGEX()))
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
