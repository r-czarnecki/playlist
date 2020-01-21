#ifndef KLASY_PLAYABLEFACTORY_H
#define KLASY_PLAYABLEFACTORY_H

#include <map>
#include <memory>
#include <functional>
#include "Playable.h"

class PlayableFactory {
private:
    using pPlayable = std::shared_ptr<Playable>;
    using TPlayable = std::function<pPlayable(const std::string &)>;
    static std::map<std::string, TPlayable> &playableTypes();

public:
    PlayableFactory() = delete;

    static bool registerPlayableType(const std::string& name, TPlayable playable);
    static pPlayable create(const std::string &type, const std::string &description);
};

#endif //KLASY_PLAYABLEFACTORY_H
