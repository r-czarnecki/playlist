#ifndef KLASY_PLAYABLEFACTORY_H
#define KLASY_PLAYABLEFACTORY_H

#include <map>
#include <memory>
#include <functional>
#include "Playable.h"
#include "PlayableWithContent.h"

class PlayableFactory {
private:
    using pPlayable = std::shared_ptr<PlayableWithContent>;
    using TPlayable = std::function<pPlayable(const TagSplitter::tagMap &, const std::string &)>;
    static std::map<std::string, TPlayable> &playableTypes();

public:
    PlayableFactory() = delete;

    static bool registerPlayableType(const std::string& name, TPlayable playable);
    static pPlayable
    create(const std::string &type, const TagSplitter::tagMap &description, const std::string &content);
};

#endif //KLASY_PLAYABLEFACTORY_H
