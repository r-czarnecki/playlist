#include "Player.h"
#include "PlayableFactory.h"

std::shared_ptr<Playable> Player::openFile(File file) {
    return PlayableFactory::create(file.getType(), file.getDescription());
}

std::shared_ptr<Playlist> Player::createPlaylist(const std::string& name) {
    return std::make_shared<Playlist>(name);
}