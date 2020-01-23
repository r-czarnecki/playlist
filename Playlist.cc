#include <iostream>
#include "Playlist.h"
#include "SequenceMode.h"
#include "lib_playlist.h"
#include "PositionDoesNotExistException.h"
#include "CycleException.h"


Playlist::Playlist(string name)
: elements()
, starter(createSequenceMode())
, name(name) {}

void Playlist::add(shared_ptr<Playable> element) {
    add(element, elements.size());
}

void Playlist::add(shared_ptr<Playable> element, int position) {
    if(position < 0 || position > (int)elements.size())
        throw PositionDoesNotExistException();

    if(doesPathExist(element))
        throw CycleException();

    elements.insert(elements.begin() + position, element);
}

void Playlist::remove() {
    elements.pop_back();
}

void Playlist::remove(int position) {
    if(position < 0 || position >= (int)elements.size())
        throw PositionDoesNotExistException();

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

bool Playlist::hasElements() {
    return true;
}

std::vector<std::shared_ptr<Playable>> *Playlist::getElements() {
    return &elements;
}

bool Playlist::doesPathExist(shared_ptr<Playable> from) {
    if(!from->hasElements())
        return false;
        
    for(shared_ptr<Playable> playlist : *from->getElements())
        if(playlist.get() == this || doesPathExist(playlist))
            return true;
    
    return false;
}