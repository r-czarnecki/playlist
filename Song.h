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
    explicit Song(const std::string &description);

    static std::string factoryName() { return "audio"; }
    static std::shared_ptr<Playable> createType(const std::string &description)
    { return std::make_shared<Song>(description); }

    std::string type() override;
    std::string header() override;
    std::string description() override;
    void play() override;
};

#endif //KLASY_SONG_H
