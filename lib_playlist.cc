#include "lib_playlist.h"

std::shared_ptr<PlayMode> createSequenceMode() {
    return std::move(std::make_shared<SequenceMode>(SequenceMode()));
}

std::shared_ptr<PlayMode> createShuffleMode(long long int seed) {
    return std::move(std::make_shared<ShuffleMode>(ShuffleMode(seed)));
}

std::shared_ptr<PlayMode> createOddEvenMode() {
    return std::move(std::make_shared<OddEvenMode>(OddEvenMode()));
}