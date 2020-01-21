#include <iostream>
#include "Playable.h"
#include "TagSplitter.h"


void Playable::play() {
    std::cout << type() << " [" << header() <<"]: " << description() << std::endl;
}

Playable::Playable(const std::string &description)
: playableTags (TagSplitter::splitTags(description)) {

}
