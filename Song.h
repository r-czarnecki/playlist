#ifndef KLASY_SONG_H
#define KLASY_SONG_H

#include <string>
#include <memory>
#include "PlayableWithContent.h"

class Song : public PlayableWithContent {
private:
    static bool isRegistered;
    std::string artist;
    std::string title;

public:
    explicit Song(const TagSplitter::tagMap &description, const std::string &content);

    static std::string factoryName() { return "audio"; }
    static std::shared_ptr<PlayableWithContent> createType(const TagSplitter::tagMap &description, const std::string &content)
    { return std::make_shared<Song>(description, content); }

    std::string type() override;
    std::string header() override;
};

#endif //KLASY_SONG_H
