#include <iostream>
#include "Playable.h"


void Playable::play() {
    std::cout << type() << " [" << header() <<"]: " << description() << std::endl;
}
