#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>

std::string word_to_number_converter(std::string string_input){
  std::string string_solution = "";
  int POSSIBLE_NUMBERS_LENGTH = 9;
  std::string possible_numbers[POSSIBLE_NUMBERS_LENGTH] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  std::string possible_number;
  std::map<std::string, std::string> words_to_numbers { {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};

  bool changes_made = false;
  for (int i = 0; i < string_input.size(); i++){
    for (int j = 0; j < POSSIBLE_NUMBERS_LENGTH; j++){
      possible_number = possible_numbers[j];
      int test_range = string_input.size()-possible_number.size();
      if (i <= test_range){
        std::string test_substring = string_input.substr(i, possible_number.size());
        if (test_substring == possible_number){
          string_solution += words_to_numbers[possible_number];
          changes_made = true;
        }
      }
    }
    if (changes_made == false){
      string_solution += string_input.substr(i, 1);
    }
    changes_made = false;
  }
  return string_solution;
}

int string_to_solution(std::string string_input){
  int data_length = string_input.size();
  int ascii_array[data_length];
  for (int j=0; j<data_length; j++){
      std::string current_letter = string_input.substr(j, 1);
      ascii_array[j] = current_letter[0];
  }
  int first_number = 0;
  int last_number = 0;
  bool first_number_found = false;
  for (int k=0; k<data_length; k++){
      if (ascii_array[k]>48 && ascii_array[k] <58){
          if (!first_number_found){
              first_number = ascii_array[k]-48;
              first_number_found = true;
          }
          last_number = ascii_array[k]-48;
      }
  }
  std::string n1 = std::to_string(first_number);
  std::string n2 = std::to_string(last_number);
  std::string combined_number = n1+n2;
  return std::stoi(combined_number);
}

int main(){
  std::vector<std::string> inputLines;
  std::ifstream inputFile("input.txt");
  int solution = 0;

  if (!inputFile) {
      std::cerr << "Error opening input file" << std::endl;
      return -1;
  }

  std::string line;
  while (getline(inputFile, line)){
    inputLines.push_back(line);
  }

  for (int i = 0; i < inputLines.size(); i++){
    line = inputLines[i];
    std::remove_if(line.begin(), line.end(), isspace);
    line = word_to_number_converter(line);
    solution += string_to_solution(line); 
  }

  std::cout << solution << std::endl;

  return 0;
}