#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include <memory>
#include <string>
#include "Playable.h"
#include "PlayMode.h"
using namespace std;

class Playlist : public Playable {
public:
    Playlist(string name);
    void add(shared_ptr<Playable> element);
    void add(shared_ptr<Playable> element, int position);
    void remove();
    void remove(int position);
    void setMode(PlayMode& mode);
    
    void play() override;
    std::string type() override;
    std::string header() override;
    std::string description() override;

private:
    vector<shared_ptr<Playable>> elements;
    unique_ptr<PlayMode> mode;
    string name;
};

#endif