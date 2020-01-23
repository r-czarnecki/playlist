#include <algorithm>
#include <random>
#include "ShuffleMode.h"

ShuffleMode::ShuffleMode(int size, long long int seed) {
    this->size = size;
    this->seed = seed; 
    positions.resize(size);

    for(int i = 0; i < size; i++)
        positions[i] = i;
    
    shuffle(positions.begin(), positions.end(), default_random_engine(seed));
    currentPosition = 0;
}

int ShuffleMode::next() {
    if(currentPosition >= size)
        return -1;
    
    int tmp = currentPosition;
    currentPosition++;
    return positions[tmp];
}