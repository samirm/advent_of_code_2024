#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../util/util.h"
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream input("day 2/data/test.txt");

    if (!input.is_open()) {
        cerr << "Error opening file" << endl;
        return -1;
    }

    input.close();
    return 0;
}