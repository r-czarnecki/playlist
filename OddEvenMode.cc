#include "OddEvenMode.h"

OddEvenMode::OddEvenMode(int size) {
    this->size = size;
    currentPosition = (size < 2) ? 0 : 1;
}

int OddEvenMode::next() {
    if(currentPosition >= size && currentPosition % 2 == 0)
        return -1;
    if(currentPosition >= size)
        currentPosition = 0;

    int tmp = currentPosition;
    currentPosition += 2;

    return tmp;
}