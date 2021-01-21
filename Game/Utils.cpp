//
// Created by Zheng on 24/11/2020.
//


#include "Utils.h"

int utils::generateRandomNumber(int from, int to) {
    std::uniform_int_distribution<int> distribution(from,to);
    return distribution(generator);
}

float utils::generateRandomNumberf(float from, float to, int n_decimal) {
    std::uniform_real_distribution<float> distribution(from,to);
    return roundf(distribution(generator), n_decimal);
}

std::vector<int> utils::generateRandomNumbers(int from, int to, int n) {
    std::uniform_int_distribution<int> distribution(from,to);
    std::vector<int> numbers;
    numbers.reserve(n);
    for(int i = 0 ; i < n ; i++){
        numbers.push_back(distribution(generator));
    }
    return numbers;
}

bool utils::trueFalse(float probability) {
    std::uniform_real_distribution<float> distribution(0,100);
    float res = distribution(generator);
    return  res < probability;
}

float utils::roundf(float n, int n_decimals) {
    float app = std::pow(10, n_decimals);
    return std::roundf(n * app) / app;
}

std::string utils::textWrap(sf::Text &label, const std::string& wrap_text, float line_length) {
    stringstream ss;
    std::vector<std::string> lines;
    bool remain_words;
    for(char c : wrap_text) {
        remain_words = true;
        ss << c;
        label.setString(ss.str());
        if(label.getGlobalBounds().width > line_length){
            ss << std::endl;
            lines.push_back(ss.str());
            ss.str("");
            remain_words = false;
        }
    }
    if(remain_words)
        lines.push_back(ss.str());
    std::string final_testo;
    for(const auto& i : lines)
        final_testo += i;

    return final_testo;
}

float utils::absoluteValue(float a) {
    return abs(a);
}

bool utils::fileExists(const std::string& path) {
    std::ifstream infile(path);
    return infile.good();
}

std::string utils::readFile(const std::string& path) {
    std::fstream fin;
    std::string app;
    std::stringstream ss;
    fin = std::fstream(path, std::fstream::in);
    if(fin.is_open()){
        while(getline(fin, app)){
            ss << app << std::endl;
        }
        fin.close();
    }else{
        std::cerr<<"Could not read [" << path << "]" << std::endl;
    }
    return ss.str();
}

bool utils::writeStringToFile(const std::string& content, const std::string& path) {
    std::ofstream myfile (path);
    if(myfile.is_open()){
        myfile << content;
        myfile.close();
    }else{
        std::cerr<< "Could not write to file" << std::endl;
        return false;
    }
    return true;
}

std::string utils::getFileExtension(const string &file_name) {
    std::stringstream res;
    for(int i = 0; i< file_name.length(); i++) {
        if(file_name.at(i) == '.'){
            res << file_name.substr(i, file_name.length() - 1);
            break;
        }
    }
    return res.str();
}

std::string utils::getFileName(const string &file_name) {
    std::stringstream res;
    for(int i = 0; i< file_name.length(); i++) {
        if(file_name.at(i) == '.'){
            res << file_name.substr(0, i);
            break;
        }
    }
    return res.str();
}

bool utils::lineRectIntersect(const sf::FloatRect &rect, const sf::Vector2f &a_p1, const sf::Vector2f &a_p2) {
    auto minX = std::min(a_p1.x, a_p2.x);
    auto maxX = std::max(a_p1.x, a_p2.x);
    if (maxX > rect.left + rect.width) {
        maxX = rect.left + rect.width;
    }
    if (minX < rect.left) {
        minX = rect.left;
    }
    if (minX > maxX) {
        return false;
    }
    auto minY = a_p1.y;
    auto maxY = a_p2.y;
    auto dx = a_p2.x - a_p1.x;
    if (std::abs(dx) > 0.0000001f) {
        auto k = (a_p2.y - a_p1.y) / dx;
        auto b = a_p1.y - k * a_p1.x;
        minY = k * minX + b;
        maxY = k * maxX + b;
    }
    if (minY > maxY) {
        std::swap(minY, maxY);
    }
    if (maxY > rect.top + rect.height) {
        maxY = rect.top + rect.height;
    }
    if (minY < rect.top) {
        minY = rect.top;
    }
    if (minY > maxY) {
        return false;
    }
    return true;
}
