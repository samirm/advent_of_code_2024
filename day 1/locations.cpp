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
    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());

    vector<int> diffs(leftList.size());
    for (auto i = 0; i < leftList.size(); i++) {
        diffs[i] = abs(leftList[i] - rightList[i]);
    }

    cout << abs(leftList[0] - rightList[0]) << endl;
    printVector(diffs);
    cout << "left" << endl;
    printVector(leftList);
    cout << "right" << endl;
    printVector(rightList);
    auto sum = accumulate(diffs.begin(), diffs.end(), 0);
    cout << "sum" << endl;
    cout << sum << endl;

    input.close();
    return 0;
}

