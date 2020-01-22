#include <iostream>
#include "Playlist.h"
#include "SequenceMode.h"

Playlist::Playlist(string name)
: elements()
, mode(new SequenceMode())
, name(name) {}

void Playlist::add(shared_ptr<Playable> element) {
    elements.push_back(element);
}

void Playlist::add(shared_ptr<Playable> element, int position) {
    elements.insert(elements.begin() + position, element);
}

void Playlist::remove() {
    elements.pop_back();
}

void Playlist::remove(int position) {
    elements.erase(elements.begin() + position);
}

void Playlist::setMode(shared_ptr<PlayMode> mode) {
    this->mode = move(mode);
}

void Playlist::play() {
    cout << type() + " [" + header() + "]\n";

    int pos = mode->start(elements.size());
    
    while(pos != -1) {
        elements[pos]->play();
        pos = mode->next();
    }
}

std::string Playlist::type() {
    return "Playlist";
}

std::string Playlist::header() {
    return name;
}

std::string Playlist::description() {
    return "";
}