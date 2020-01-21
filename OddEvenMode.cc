#include "OddEvenMode.h"

int OddEvenMode::start(int size) {
    this->size = size;
    currentPosition = (size < 2) ? 0 : 1;
    return currentPosition;
}

int OddEvenMode::next() {
    if(currentPosition >= size - 2 && currentPosition % 2 == 0)
        return -1;
    
    if(currentPosition >= size - 2)
        currentPosition = 0;
    else
        currentPosition += 2;

    return currentPosition;
}