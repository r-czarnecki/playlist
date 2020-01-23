#include <iostream>
#include "Playable.h"
#include "TagSplitter.h"


void Playable::play() {
    std::cout << type() << " [" << header() <<"]: " << description() << std::endl;
}

Playable::Playable(const std::string &description, bool omitMetadata)
: playableTags (TagSplitter::splitTags(description, omitMetadata))
, elements() {

}

bool Playable::hasElements() {
    return false;
}

std::vector<std::shared_ptr<Playable>> *Playable::getElements() {
    return nullptr;
}