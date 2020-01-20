#ifndef KLASY_PLAYABLE_H
#define KLASY_PLAYABLE_H

class Playable {
public:
    virtual void play();

    virtual std::string type() = 0;
    virtual std::string header() = 0;
    virtual std::string description() = 0;
};

#endif //KLASY_PLAYABLE_H
