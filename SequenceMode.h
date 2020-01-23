#ifndef SEQUENCEMODE_H
#define SEQUENCEMODE_H

#include "PlayMode.h"

class SequenceMode : public PlayMode {
public:
    SequenceMode(int size);
    int next() override;
};

#endif