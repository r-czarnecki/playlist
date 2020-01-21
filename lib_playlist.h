#ifndef LIBPLAYLIST_H
#define LIBPLAYLIST_H

#include "SequenceMode.h"
#include "ShuffleMode.h"
#include "OddEvenMode.h"

SequenceMode createSequenceMode();
ShuffleMode createShuffleMode(long long int seed);
OddEvenMode createOddEvenMode();

#endif