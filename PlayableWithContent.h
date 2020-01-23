#ifndef KLASY_PLAYABLEWITHCONTENT_H
#define KLASY_PLAYABLEWITHCONTENT_H


#include "Playable.h"

class PlayableWithContent : public Playable {
protected:
    std::string content;
    std::string description() override;

public:
    PlayableWithContent(const TagSplitter::tagMap &description, const std::string &content)
    : Playable(description)
    , content(content) {}

};


#endif //KLASY_PLAYABLEWITHCONTENT_H
