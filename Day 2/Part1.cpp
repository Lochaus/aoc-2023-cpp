#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

// Function to split the bag reveals
std::vector<std::string> get_bag_reveal(std::string subGame){
    std::vector<std::string> bagReveal;
    std::string s;
    std::stringstream ss(subGame);

    while (getline(ss, s, ',')){
        bagReveal.push_back(s);
    }
    
    return bagReveal;
}

// Function to get colour of each reveal
std::string get_colour(std::string bag){
    std::string finalLetter;
    finalLetter = bag.substr(bag.size() - 1, 1);
    if (finalLetter == "d"){
        return "red";
    } else if (finalLetter == "n"){
        return "green";
    } else if (finalLetter == "e"){
        return "blue";
    }
}

// Logic to check if bag contents exceed max 
bool rgb_count(std::string input){
    std::vector<std::string> subGame;
    std::string s;
    std::stringstream ss(input);
    std::string colour;

    while (getline(ss, s, ';')){
        subGame.push_back(s);
    }

    for (int i = 0; i < subGame.size(); i++){
        std::vector<std::string> bagReveal = get_bag_reveal(subGame[i]);
        std::map<std::string, int> colourCounter { {"red", 0}, {"green", 0}, {"blue", 0}};
        for (int j = 0; j < bagReveal.size(); j++){
            std::string currentReveal = bagReveal[j];
            std::string colour = get_colour(currentReveal);
            currentReveal.erase(currentReveal.find(colour), colour.length());
            colourCounter[colour] += std::stoi(currentReveal);
        }
        if (colourCounter["red"] > 12){
            return false;
        } else if (colourCounter["green"] > 13){
            return false;
        } else if (colourCounter["blue"] > 14){
            return false;
        }
    }
    return true;
}

int main() {
    int solution = 0;
    std::vector<std::string> inputLines;
    std::vector<std::string> splitString;
    std::ifstream inputFile("input.txt");

    if (!inputFile) {
        std::cerr << "Error opening input file" << std::endl;
        return -1;
    }

    std::string line;
    while (getline(inputFile, line)){
        inputLines.push_back(line);
    }

    // Logic to organise input into usable vector
    for (int i = 0; i < inputLines.size(); i++){
        std::string game_number = std::to_string(i+1);
        line = inputLines[i];
        line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
        line = line.substr( 5  + game_number.size(), line.size() - 5 + game_number.size());
        std::replace(inputLines.begin(), inputLines.end(), inputLines[i], line);
    }

    for (int i = 0; i < inputLines.size(); i++){
        if (rgb_count(inputLines[i]) == 1){
            solution += (i + 1);
        }
    }

    std::cout << solution << std::endl;
    return 0;
}