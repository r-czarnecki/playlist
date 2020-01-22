#include <iostream>
#include "Playable.h"
#include "TagSplitter.h"


void Playable::play() {
    std::cout << type() << " [" << header() <<"]: " << description() << std::endl;
}

Playable::Playable(const std::string &description, bool omitMetadata)
: playableTags (TagSplitter::splitTags(description, omitMetadata)) {

}
