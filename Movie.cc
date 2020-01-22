#include <iostream>
#include "Movie.h"
#include "PlayableFactory.h"
#include "TagSplitter.h"

bool Movie::isRegistered = PlayableFactory::registerPlayableType(Movie::factoryName(), Movie::createType);

std::string Movie::type() {
    return "Movie";
}

std::string Movie::header() {
    return title + ", " + year;
}

std::string Movie::description() {
    return displayText;
}

Movie::Movie(const std::string &description)
: Playable(description, true)
, displayText(TagSplitter::decodeROT13(TagSplitter::getContent(description))) {
    // TODO: Wyjątki (jeśli nie znaleziono tagów 'title' i 'year')

    if (playableTags.count("title"))
        title = playableTags["title"];
    if (playableTags.count("year"))
        year = playableTags["year"];

    std::cout << "Movie: ";
    play();
    std::cout << std::endl;
}

void Movie::play() {
    if (std::regex_match(displayText, TagSplitter::ALLOWED_CONTENT_REGEX()))
        Playable::play();
    else {
        // TODO: Rzuć wyjątek (treść zawiera niedozwolone znaki)
    }
}
