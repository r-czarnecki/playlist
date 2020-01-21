#include <iostream>
#include "Movie.h"
#include "PlayableFactory.h"
#include "TagSplitter.h"

bool Movie::isRegistered = PlayableFactory::registerPlayableType(Movie::factoryName(), Movie::createType);

std::string Movie::type() {
    return "Movie";
}

std::string Movie::header() {
    return title + year;
}

std::string Movie::description() {
    return displayText;
}

Movie::Movie(const std::string &description) : Playable(description), displayText(TagSplitter::getContent(description)) {
    // TODO: Wyjątki (jeśli nie znaleziono tagów 'title' i 'year')
    // TODO: Odkoduj ROT13

    if (playableTags.count("title"))
        title = playableTags["title"];
    if (playableTags.count("year"))
        year = playableTags["year"];

    std::cout << "Movie: ";
    play();
    std::cout << std::endl;
}
