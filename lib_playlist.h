#ifndef LIBPLAYLIST_H
#define LIBPLAYLIST_H

#include <memory>
#include "PlayModeStarter.h"
#include "Player.h"
#include "PlayerException.h"

std::shared_ptr<PlayModeStarter> createSequenceMode();
std::shared_ptr<PlayModeStarter> createShuffleMode(long long int seed);
std::shared_ptr<PlayModeStarter> createOddEvenMode();

#endif