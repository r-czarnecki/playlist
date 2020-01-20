#include "Song.h"
#include "PlayableFactory.h"

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