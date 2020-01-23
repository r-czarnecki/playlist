#include <iostream>
#include "Playlist.h"
#include "SequenceMode.h"
#include "lib_playlist.h"

Playlist::Playlist(string name)
: elements()
, starter(createSequenceMode())
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

void Playlist::setMode(shared_ptr<PlayModeStarter> starter) {
    this->starter = starter;
}

void Playlist::play() {
    cout << type() + " [" + header() + "]\n";

    auto mode = starter->create(elements.size());
    
    for(int pos = mode->next(); pos != -1; pos = mode->next())
        elements[pos]->play();
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