#ifndef SHUFFLEMODE_H
#define SHUFFLEMODE_H

#include <vector>
#include "PlayMode.h"
using namespace std;

class ShuffleMode : public PlayMode {
public:
    ShuffleMode(int size, long long int seed);
    int next() override;

private:
    long long int seed;
    vector<int> positions;
};

#endif