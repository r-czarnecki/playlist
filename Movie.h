#ifndef KLASY_MOVIE_H
#define KLASY_MOVIE_H

#include <string>
#include <memory>
#include "PlayableWithContent.h"

class Movie : public PlayableWithContent {
private:
    static bool isRegistered;
    std::string title;
    int year;
    
protected:
    std::string type() override;
    std::string header() override;

public:
    explicit Movie(const TagSplitter::tagMap &description, const std::string &content);

    static std::string factoryName() { return "video"; }
    static std::shared_ptr<PlayableWithContent> createType(const TagSplitter::tagMap &description, const std::string &content)
    { return std::make_shared<Movie>(description, content); }
};

#endif //KLASY_MOVIE_H
