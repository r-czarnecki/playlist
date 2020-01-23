#ifndef PLAYMODE_H
#define PLAYMODE_H

#include <memory>
using namespace std;

class PlayMode {
public:
    virtual int next() = 0;

protected:
    int size;
    int currentPosition;
};

#endif