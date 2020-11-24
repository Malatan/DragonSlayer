//
// Created by Administrator on 24/11/2020.
//

#include "Utils.h"

int utils::generateRandomNumber(int from, int to, bool resetSeed) {
    if(resetSeed)
        srand((unsigned) time(nullptr));
    return (rand() % (to-from+1)) + from;
}

std::vector<int> utils::generateRandomNumbers(int from, int to, int n, bool resetSeed) {
    if(resetSeed)
        srand((unsigned) time(nullptr));

    std::vector<int> numbers;
    for(int i = 0 ; i < n ; i++){
        numbers.push_back((rand() % (to-from+1)) + from);
    }
    return numbers;
}

bool utils::trueFalse(float probability, bool resetSeed) {
    if(resetSeed)
        srand((unsigned) time(nullptr));
    return (rand() % 100) < probability;
}
