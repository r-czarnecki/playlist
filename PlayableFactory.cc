#include "PlayableFactory.h"
#include "UnsupportedTypeException.h"

bool PlayableFactory::registerPlayableType(const std::string& name, PlayableFactory::TPlayable playable) {
    if (auto it = playableTypes().find(name); it != playableTypes().end())
        return false;

    playableTypes()[name] = playable;
    return true;
}

PlayableFactory::pPlayable PlayableFactory::create(const std::string &type, const std::string &description) {
    if (auto it = playableTypes().find(type); it != playableTypes().end())
        return it->second(description);
    else
        throw UnsupportedTypeException();
}

std::map<std::string, PlayableFactory::TPlayable> &PlayableFactory::playableTypes()  {
    static std::map<std::string, TPlayable> playables;

    return playables;
}
