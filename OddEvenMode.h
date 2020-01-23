#ifndef ODDEVENMODE_H
#define ODDEVENMODE_H

#include "PlayMode.h"

class OddEvenMode : public PlayMode {
public:
    OddEvenMode(int size);
    int next() override;
};

#endif