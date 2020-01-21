#ifndef ODDEVENMODE_H
#define ODDEVENMODE_H

#include "PlayMode.h"

class OddEvenMode : public PlayMode {
public:
    int start(int size) override;
    int next() override;
};

#endif