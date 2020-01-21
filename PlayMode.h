#ifndef PLAYMODE_H
#define PLAYMODE_H

class PlayMode {
public:
    virtual int start(int size) = 0;
    virtual int next() = 0;

protected:
    int size;
    int currentPosition;
};

#endif