#include <iostream>
#include "Song.h"
#include "PlayableFactory.h"
#include "TagSplitter.h"

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
    // TODO: Wyjątki (jeśli nie ma 'title' lub 'artist')

    if (playableTags.count("title"))
        title = playableTags["title"];
    if (playableTags.count("artist"))
        artist = playableTags["artist"];

    std::cout << "Song: ";
    play();
    std::cout << std::endl;
}

void Song::play() {
    if (std::regex_match(lyrics, TagSplitter::ALLOWED_CONTENT_REGEX()))
        Playable::play();
    else {
        // TODO: Rzuć wyjątek (treść zawiera niedozwolone znaki)
    }
}
