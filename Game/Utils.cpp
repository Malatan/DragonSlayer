//
// Created by Administrator on 24/11/2020.
//

#include "Utils.h"

int utils::generateRandomNumber(int from, int to) {
    std::random_device rd;
    static std::default_random_engine generator(rd()); // rd() provides a random seed
    std::uniform_int_distribution<int> distribution(from,to);
    return distribution(generator);
}

std::vector<int> utils::generateRandomNumbers(int from, int to, int n) {
    std::random_device rd;
    static std::default_random_engine generator(rd()); // rd() provides a random seed
    std::uniform_int_distribution<int> distribution(from,to);
    std::vector<int> numbers;
    numbers.reserve(n);
    for(int i = 0 ; i < n ; i++){
        numbers.push_back(distribution(generator));
    }
    return numbers;
}

bool utils::trueFalse(float probability) {
    std::random_device rd;
    static std::default_random_engine generator(rd()); // rd() provides a random seed
    std::uniform_real_distribution<float> distribution(0,100);
    float res = distribution(generator);
    return  res < probability;
}

float utils::roundf(float n, int n_decimals) {
    float app = std::pow(10, n_decimals);
    return std::roundf(n * app) / app;
}

