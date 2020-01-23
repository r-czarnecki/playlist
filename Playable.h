#ifndef KLASY_PLAYABLE_H
#define KLASY_PLAYABLE_H

#include <map>
#include <vector>
#include <memory>

class Playable {
protected:
    std::map<std::string, std::string> playableTags;
    std::vector<std::shared_ptr<Playable>> elements;

public:
    Playable() = default;
    explicit Playable(const std::string &description, bool omitMetadata = true);
    virtual ~Playable() = default;

    virtual void play();

    virtual std::string type() = 0;
    virtual std::string header() = 0;
    virtual std::string description() = 0;

    virtual bool hasElements();
    virtual std::vector<std::shared_ptr<Playable>> *getElements();
};

#endif //KLASY_PLAYABLE_H
