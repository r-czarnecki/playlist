#ifndef KLASY_PLAYER_H
#define KLASY_PLAYER_H

#include <string>
#include <memory>
#include "Playable.h"
#include "File.h"

class Player {

public:
    std::unique_ptr<Playable> openFile(File file);
    std::unique_ptr<Playlist> createPlaylist(std::string name);


};

#endif //KLASY_PLAYER_H
