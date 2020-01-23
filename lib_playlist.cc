#include "lib_playlist.h"
#include "OddEvenMode.h"
#include "ShuffleMode.h"
#include "SequenceMode.h"

std::shared_ptr<PlayModeStarter> createSequenceMode() {
    return make_shared<PlayModeStarter>(PlayModeStarter([](int size){
        return make_unique<SequenceMode>(SequenceMode(size));
    }));
}

std::shared_ptr<PlayModeStarter> createShuffleMode(long long int seed) {
    return make_shared<PlayModeStarter>(PlayModeStarter([seed](int size){
        return make_unique<ShuffleMode>(ShuffleMode(size, seed));
    }));
}

std::shared_ptr<PlayModeStarter> createOddEvenMode() {
    return make_shared<PlayModeStarter>(PlayModeStarter([](int size){
        return make_unique<OddEvenMode>(OddEvenMode(size));
    }));
}