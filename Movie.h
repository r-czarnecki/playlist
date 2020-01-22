#ifndef KLASY_MOVIE_H
#define KLASY_MOVIE_H

#include <string>
#include <memory>
#include "Playable.h"

class Movie : public Playable {
private:
    static bool isRegistered;
    std::string title;
    std::string year;
    std::string displayText;

public:
    explicit Movie(const std::string &description);

    static std::string factoryName() { return "video"; }
    static std::shared_ptr<Playable> createType(const std::string &description)
    { return std::make_shared<Movie>(description); }

    std::string type() override;
    std::string header() override;
    std::string description() override;
    void play() override;
};

#endif //KLASY_MOVIE_H
