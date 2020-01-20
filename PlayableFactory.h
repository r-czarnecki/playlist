#ifndef KLASY_PLAYABLEFACTORY_H
#define KLASY_PLAYABLEFACTORY_H

#include <map>
#include <memory>
#include "Playable.h"

class PlayableFactory {
private:
    using TPlayable = std::unique_ptr<Playable>(*)();
    static std::map<std::string, TPlayable> &playableTypes();

public:
    PlayableFactory() = delete;

    static bool registerPlayableType(const std::string& name, TPlayable playable);
    static std::unique_ptr<Playable> create(const std::string& type);
};

#endif //KLASY_PLAYABLEFACTORY_H
