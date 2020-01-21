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
    static std::string factoryName() { return "video"; }
    static std::shared_ptr<Playable> createType() { return std::make_shared<Movie>(); }

    std::string type() override;
    std::string header() override;
    std::string description() override;
};

#endif //KLASY_MOVIE_H
