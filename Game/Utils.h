//
// Created by Administrator on 24/11/2020.
//

#ifndef DRAGONSLAYER_UTILS_H
#define DRAGONSLAYER_UTILS_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include "ResourcesHandler.h"

namespace utils{
    int generateRandomNumber(int from, int to);
    std::vector<int> generateRandomNumbers(int from, int to, int n);
    bool trueFalse(float probability);
    float roundf(float n, int n_decimals);
}
#endif //DRAGONSLAYER_UTILS_H
