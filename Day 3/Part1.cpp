#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

// Function to calculate the gear ratio if symbol has exactly 2 surrounding numbers
int gear_ratio(std::string inputArray[][], int y_range, int x_range) {
    int sum = 0;
    
    return sum;
}

int main() {
    int solution = 0;
    std::vector<std::string> inputLines;
    std::vector<int> symbolCoordinates;
    std::ifstream inputFile("input.txt");
    int coordinatesArray[2]; 
    int asciiLetter;

    if (!inputFile) {
        std::cerr << "Error opening input file" << std::endl;
        return -1;
    }

    std::string line;
    while (getline(inputFile, line)){
        inputLines.push_back(line);
    }

    // Initialise and create 2d array of inputlines. Size is predefined but works with changing input
    std::string inputArray[inputLines.size()][inputLines[0].size()];
    for (int y = 0; y < inputLines.size(); y++){
        for (int x = 0; x < inputLines[0].size(); x++){
            inputArray[y][x] = inputLines[y].substr(x, 1);
        }
    }

    int y_range = inputLines.size();
    int x_range = inputLines[0].size();
    for (int y = 0; y < y_range; y++){
        for (int x = 0; x < x_range; x++){
            asciiLetter = inputArray[y][x][0];
            if ((asciiLetter < 48 || asciiLetter > 57) && asciiLetter != 46){
                std::cout << "Send to Calculation Function" << std::endl;
            }
        }
    }
    return 0;
}