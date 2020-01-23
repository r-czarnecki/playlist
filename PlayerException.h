#ifndef PLAYEREXCEPTION_H
#define PLAYEREXCEPTION_H

#include <exception>
using namespace std;

class PlayerException : public exception {
public:
    virtual char const* what() const throw() = 0;
};

class PositionDoesNotExist : public PlayerException {
public:
    char const* what() const throw() override { return "Position does not exist."; }
};

class ThereIsACycle : public PlayerException {
public:
    char const* what() const throw() override { return "Playlists create a cycle."; }
};

#endif