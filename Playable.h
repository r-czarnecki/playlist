#ifndef KLASY_PLAYABLE_H
#define KLASY_PLAYABLE_H

#include <map>
#include <vector>
#include <memory>
#include "TagSplitter.h"

class Playable {
protected:
    TagSplitter::tagMap playableTags;
    std::vector<std::shared_ptr<Playable>> elements;

    virtual std::string type() = 0;
    virtual std::string header() = 0;
    virtual std::string description() = 0;

public:
    Playable() = default;
    explicit Playable(const TagSplitter::tagMap &description);
    virtual ~Playable() = default;

    virtual void play();

    virtual bool hasElements();
    virtual std::vector<std::shared_ptr<Playable>> *getElements();
};

#endif //KLASY_PLAYABLE_H
