#ifndef LIBPLAYLIST_H
#define LIBPLAYLIST_H

#include <memory>
#include "SequenceMode.h"
#include "ShuffleMode.h"
#include "OddEvenMode.h"
#include "Player.h"
#include "PlayerException.h"

std::shared_ptr<PlayMode> createSequenceMode();
std::shared_ptr<PlayMode> createShuffleMode(long long int seed);
std::shared_ptr<PlayMode> createOddEvenMode();

#endif