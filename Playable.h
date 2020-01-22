#ifndef KLASY_PLAYABLE_H
#define KLASY_PLAYABLE_H

#include <map>

class Playable {
protected:
    std::map<std::string, std::string> playableTags;

public:
    Playable() = default;
    explicit Playable(const std::string &description, bool omitMetadata = true);
    virtual ~Playable() = default;

    virtual void play();

    virtual std::string type() = 0;
    virtual std::string header() = 0;
    virtual std::string description() = 0;
};

#endif //KLASY_PLAYABLE_H
