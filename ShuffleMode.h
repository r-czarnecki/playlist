#ifndef SHUFFLEMODE_H
#define SHUFFLEMODE_H

#include <vector>
#include "PlayMode.h"
using namespace std;

class ShuffleMode : public PlayMode {
public:
    ShuffleMode(long long int seed);
    int start(int size) override;
    int next() override;

private:
    long long int seed;
    vector<int> positions;
};

#endif