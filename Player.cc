#include "Player.h"
#include "PlayableFactory.h"

std::unique_ptr<Playable> Player::openFile(File file) {
    return PlayableFactory::create(file.getType());
}
