#include <iostream>
#include <map>
#include <string>
#include "converter_functions.hpp"

int main(){

    // getting user input
    std::string user_input = "";
    std::cout << "NOTE: Hex must start with # and RGB must be enclosed in ()" << "\n";
    std::cout << "[?] Enter a Hex or RGB Value: ";
    std::getline(std::cin, user_input); // using getline because cin stops after commas and spaces

    // removing all spaces within user input for the sake of making sure values are correctly placed
    user_input = remove_spaces(user_input);

    // checking to see if its a valid hex value
    if (user_input[0] == '#'){

        // convert the entire user input into uppercase letters (to help with map searching later)
        user_input = upper_str(user_input);

        // creating substr, from 2nd character onwards (to remove # char)
        user_input = user_input.substr(1);

        // checking to see if string is alnumeric & exactly 6 chars long
        if (isalnum_str(user_input) && user_input.size() == 6){

            std::map<char, int> hex_decimal_map = {
                {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}
            };

            // checking to see if all characters in string are valid hex characters
            if (valid_hex_str(user_input, hex_decimal_map)){
                
                // mapping hex characters to decimal values
                std::map<char, int> rgb_value = hex_to_rgb(user_input, hex_decimal_map);
                
                // displaying rgb value
                std::cout << "(" << rgb_value['R'] << "," << rgb_value['G'] << "," << rgb_value['B'] << ")\n";

            } else {
                std::cout << "Invalid HEX string.\n";
            }
        }
    }
    // Checking to see if its a valid rgb code
    else if (user_input[0] == '(' && user_input[user_input.size() - 1] == ')'){

        // create a new substr removing ()
        user_input = user_input.substr(1, user_input.size()-2);

        // checking to see if characters within () are valid
        if (valid_rgb_str(user_input)){
            
            // mapping decimal values to hex characters
            std::string hex_value = rgb_to_hex(user_input);

            // displaying hex value
            std::cout << hex_value << "\n";

        } else {
            std::cout << "Invalid RGB string" << "\n";
        }
    }
    // user input is not a valid format
    else {
        std::cout << "Invalid Input!\n";
    }
}
