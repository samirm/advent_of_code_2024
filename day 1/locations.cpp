#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::ifstream input("data/test.txt");
    
    if (!input.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(input, line)) {
        std::cout << line << std::endl;
    }
    
    input.close();
    return 0;
}
