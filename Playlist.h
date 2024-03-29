#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include <memory>
#include <string>
#include <set>
#include "Playable.h"
#include "PlayModeStarter.h"
using namespace std;

class Playlist : public Playable {
public:
    Playlist(string name);
    void add(shared_ptr<Playable> element);
    void add(shared_ptr<Playable> element, int position);
    void remove();
    void remove(int position);
    void setMode(shared_ptr<PlayModeStarter> starter);
    
    void play() override;
protected:
    std::string type() override;
    std::string header() override;
    std::string description() override;

private:
    bool doesPathExist(shared_ptr<Playable> from);

    shared_ptr<PlayModeStarter> starter;
    string name;
};

#endif