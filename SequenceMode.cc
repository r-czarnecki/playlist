#include "SequenceMode.h"

int SequenceMode::start(int size) {
    this->size = size;
    currentPosition = 0;
    return currentPosition;
}

int SequenceMode::next() {
    if(currentPosition >= size - 1)
        return -1;
    
    currentPosition++;
    return currentPosition;
}