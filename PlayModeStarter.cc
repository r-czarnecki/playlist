#include "PlayModeStarter.h"

PlayModeStarter::PlayModeStarter(function<unique_ptr<PlayMode>(int)> fun) 
: fun(fun) {}

unique_ptr<PlayMode> PlayModeStarter::create(int size) {
    return fun(size);
}