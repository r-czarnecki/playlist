#include "Movie.h"
#include "PlayableFactory.h"

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
