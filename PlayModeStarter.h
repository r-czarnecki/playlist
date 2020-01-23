#ifndef PLAYMODESTARTER_H
#define PLAYMODESTARTER_H

#include <functional>
#include <memory>
#include "PlayMode.h"
using namespace std;

class PlayModeStarter {
public:
    PlayModeStarter(function<unique_ptr<PlayMode>(int)> fun);
    unique_ptr<PlayMode> create(int size);

private:
    function<unique_ptr<PlayMode>(int)> fun;
};

#endif