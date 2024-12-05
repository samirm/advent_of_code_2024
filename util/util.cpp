#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "util.h"

#include <map>

template <typename Out>

void split(const std::string &s, const char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, const char delim) {
    std::vector<std::string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

void printVector(const std::vector<int>& v) {
    for (auto i : v) {
        std::cout << i << std::endl;
    }
}

void printMap(const std::map<int, int>& m) {
    for (const auto& [key, value] : m) {
        std::cout << key << ": " << value << std::endl;
    }
}
