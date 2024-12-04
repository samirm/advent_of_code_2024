#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../util/myUtil.h"
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream input("data/input.txt");
    
    if (!input.is_open()) {
        cerr << "Error opening file" << endl;
        return -1;
    }

    string line;
    vector<int> leftList;
    vector<int> rightList;
    while (getline(input, line)) {
        auto numbers = split(line, ' ');
        leftList.push_back(stoi(numbers.front()));
        rightList.push_back(stoi(numbers.back()));
    }
    ranges::sort(leftList);
    ranges::sort(rightList);

    vector<int> diffs(leftList.size());
    for (auto i = 0; i < leftList.size(); i++) {
        diffs[i] = abs(leftList[i] - rightList[i]);
    }

    const auto sum = reduce(diffs.begin(), diffs.end());
    cout << "total distance: ";
    cout << sum << endl;

    input.close();
    return 0;
}

