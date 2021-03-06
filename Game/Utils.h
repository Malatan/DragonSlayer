//
// Created by Zheng on 24/11/2020.
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
#include <chrono>
#include <fstream>
#include "ResourcesHandler.h"

namespace utils{
    static std::default_random_engine generator(
            std::chrono::system_clock::now().time_since_epoch().count()
    );
    int generateRandomNumber(int from, int to);
    float generateRandomNumberf(float from, float to, int n_decimal);
    std::vector<int> generateRandomNumbers(int from, int to, int n);
    bool trueFalse(float probability);
    float roundf(float n, int n_decimals);
    std::string textWrap(sf::Text& label, const std::string& wrap_text, float line_length);
    float absoluteValue(float a);
    bool fileExists(const std::string& path);
    std::string readFile(const std::string& path);
    bool writeStringToFile(const std::string& content, const std::string& path);
    std::string getFileExtension(const std::string& file_name);
    std::string getFileName(const std::string& file_name);
    bool lineRectIntersect(const sf::FloatRect& rect, const sf::Vector2f& a_p1, const sf::Vector2f& a_p2);

}
#endif //DRAGONSLAYER_UTILS_H
