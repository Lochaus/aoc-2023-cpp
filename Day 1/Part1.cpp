#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    int input_size = 1000;
    int a = 0;
    int solution = 0;
    std::string input_data[input_size];
    std::ifstream file("input.txt");
    if(!file){
        std::cout << "Error opening output file" << std::endl;
        return -1;
    }
    while (!file.eof()){
        getline(file,input_data[a],'\n');
        a++;
    }
    for (int i=0; i<input_size; i++){
        std::string data = input_data[i];
        int data_length = data.size();
        int ascii_array[data_length];
        for (int j=0; j<data_length; j++){
            std::string current_letter = data.substr(j, 1);
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
        solution += std::stoi(combined_number);
    }
    std::cout << solution << std::endl;
    return 0;
}