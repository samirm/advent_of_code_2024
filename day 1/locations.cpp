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

int main(int argc, char* argv[])
{
    ifstream input("day 1/data/input.txt");
    
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

    auto sum = reduce(diffs.begin(), diffs.end());
    cout << "total distance: ";
    cout << sum << endl;

    map<int, int> histogram;
    for (int i : leftList) {
        int count = 0;
        for (int j : rightList) {
            if (i == j) count++;
        }
        histogram[i] = count;
    }

    sum = 0;
    auto it = histogram.begin();
    for (int i = 0; i < leftList.size(); i++) {
        sum += it->first*it->second;
        if (leftList[i+1] == leftList[i]) continue;
        ++it;
    }

    cout << "similarity score: ";
    cout << sum << endl;

    input.close();
    return 0;
}
