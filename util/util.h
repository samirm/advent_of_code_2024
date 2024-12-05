//
// Created by samir on 03-Dec-24.
//

#ifndef UTIL_H
#define UTIL_H

#include <map>

template <typename Out>
void split(const std::string &s, const char delim, Out result);
std::vector<std::string> split(const std::string &s, const char delim);
void printVector(const std::vector<int>& v);
void printMap(const std::map<int, int>& m);
#endif //UTIL_H
