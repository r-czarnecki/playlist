#ifndef KLASY_SONG_H
#define KLASY_SONG_H

#include <string>
#include <memory>
#include "Playable.h"

class Song : public Playable {
private:
    static bool isRegistered;
    std::string artist;
    std::string title;
    std::string lyrics;

public:
    static std::string factoryName() { return "audio"; }
    static std::unique_ptr<Playable> createType() { return std::make_unique<Song>(); }

    std::string type() override;
    std::string header() override;
    std::string description() override;
};

#endif //KLASY_SONG_H
