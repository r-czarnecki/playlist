#include "lib_playlist.h"

SequenceMode createSequenceMode() {
    return SequenceMode();
}

ShuffleMode createShuffleMode(long long int seed) {
    return ShuffleMode(seed);
}

OddEvenMode createOddEvenMode() {
    return OddEvenMode();
}