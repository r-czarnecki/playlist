#include "PlayableFactory.h"

bool PlayableFactory::registerPlayableType(const std::string& name, PlayableFactory::TPlayable playable) {
    if (auto it = playableTypes().find(name); it != playableTypes().end())
        return false;

    playableTypes()[name] = playable;
    return true;
}

std::shared_ptr<Playable> PlayableFactory::create(const std::string &type) {
    if (auto it = playableTypes().find(type); it != playableTypes().end())
        return it->second();

    return nullptr;
}

std::map<std::string, PlayableFactory::TPlayable> &PlayableFactory::playableTypes()  {
    static std::map<std::string, TPlayable> playables;

    return playables;
}
