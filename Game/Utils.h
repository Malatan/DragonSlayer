//
// Created by Administrator on 24/11/2020.
//

#ifndef DRAGONSLAYER_UTILS_H
#define DRAGONSLAYER_UTILS_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>

namespace utils{
    int generateRandomNumber(int from, int to, bool resetSeed);
    std::vector<int> generateRandomNumbers(int from, int to, int n, bool resetSeed);
    bool trueFalse(float probability, bool resetSeed);
}
#endif //DRAGONSLAYER_UTILS_H
