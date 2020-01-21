#ifndef SEQUENCEMODE_H
#define SEQUENCEMODE_H

#include "PlayMode.h"

class SequenceMode : public PlayMode {
public:
    int start(int size) override;
    int next() override;
};

#endif