#include <iostream>
#include "Playable.h"
#include "TagSplitter.h"


void Playable::play() {
    std::cout << type() << " [" << header() <<"]: " << description() << std::endl;
}

Playable::Playable(const TagSplitter::tagMap &description)
: playableTags (description)
{}

std::vector<std::shared_ptr<Playable>> &Playable::getElements() {
    return elements;
}