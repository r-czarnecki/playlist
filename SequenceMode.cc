#include "SequenceMode.h"

SequenceMode::SequenceMode(int size) {
    this->size = size;
    currentPosition = 0;
}

int SequenceMode::next() {
    if(currentPosition >= size)
        return -1;
    
    int tmp = currentPosition;
    currentPosition++;
    return tmp;
}