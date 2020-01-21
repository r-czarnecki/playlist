#include <algorithm>
#include <random>
#include "ShuffleMode.h"

ShuffleMode::ShuffleMode(long long int seed)
: seed(seed) {}

int ShuffleMode::start(int size) {
    this->size = size;
    positions.resize(size);

    for(int i = 0; i < size; i++)
        positions[i] = i;
    
    shuffle(positions.begin(), positions.end(), default_random_engine(seed));
    currentPosition = 0;
    return positions[0];
}

int ShuffleMode::next() {
    if(currentPosition >= size - 1)
        return -1;
    
    currentPosition++;
    return positions[currentPosition];
}