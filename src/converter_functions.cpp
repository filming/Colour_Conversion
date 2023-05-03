#include <string>
#include <map>

// removes all the spaces within a string
std::string remove_spaces(const std::string& str){
    std::string clean_str;

    for (const char& character : str){
        if (character != ' '){
            clean_str += character;
        }
    }

    return clean_str;
}

// converts all the lower characters in a string to the uppercase version if possible
std::string upper_str(std::string& str){

    // looping through each char in string
    for (char& character : str){

        // subtracting 32 to the value to hopeuflly make it it uppercased
        character -= 32;

        // checking to see if its not a number anymore; changing back if true
        if (!isalpha(character)){
            character += 32;
        }    
    }
    
    return str;
}

// checks to see if an entire string is alnumeric
bool isalnum_str(const std::string& str){

    // looping through each char in string
    for (const char& character : str){

        // checking to see if character is not alnumeric; returning false if true
        if (!isalnum(character)){
            return false;
        }   
    }

    return true;
}

// checks to see if all characters in string are hex characters
bool valid_hex_str(const std::string& str, const std::map<char, int>& hex_rgb_map){

    // looping through each char in string
    for (const char& character : str){

        // checking to see if current char does not exists in map; returning false if true
        if (!hex_rgb_map.count(character)){
            return false;
        } 
    }
    return true;
}

// converts hex value into rgb value
std::map<char, int> hex_to_rgb(const std::string& str, const std::map<char, int>& hex_rgb_map){
    std::map<char, int> rgb_values;

    // convert hex value into rgb value
    for (int i = 0; i < str.size(); i++){
        
        if (i % 2 != 0){
            continue;
        }

        int num1 = hex_rgb_map.find(str[i])->second;
        int num2 = hex_rgb_map.find(str[i + 1])->second;

        if (!rgb_values.count('R')){
            rgb_values['R'] = (num1 * 16) + (num2);
        } else if (!rgb_values.count('G')){
            rgb_values['G'] = (num1 * 16) + (num2);
        } else if (!rgb_values.count('B')){
            rgb_values['B'] = (num1 * 16) + (num2);
        }
    }

    return rgb_values;
}

// checks to see if a string is made up entirely of integers
bool is_number(const std::string& str){

    // looping through each character in the string
    for (const char& character : str){
        // checking character to see its the string representation of a integer; returning false if not
        if (!isdigit(character)){
            return false;
        }
    }

    return true;
}

// checking to see if str is a valid rgb str
bool valid_rgb_str(std::string str){

    // make sure there are 2 commas
    int comma_counter = 0;
    for (const char& character : str){
        if (character == ','){
            comma_counter++;
        }
    }

    if (comma_counter == 2){
        
        // split string by commas & compare what was split
        std::string temp = "";

        // adding a comma at the end of the str just to be able make sure i get all parts between commas when iterating
        str += ',';

        // looping through entire string adding the current char to a temp var until we hit a comma
        for (const char& character : str){
            if (character != ','){
                temp += character;

            } else {
                // checking to see if string contains only integers
                if (is_number(temp)){
                    int temp_int = std::stoi(temp);

                    // checking to see if number is not between 0 and 255 inclusively
                    if (!(temp_int >= 0 && temp_int <= 255)){
                        return false;
                    }

                } else {
                    // temp is not purely numbers
                    return false;
                }

                // clearing temp for next iteration
                temp = "";
            }
        }

    } else {
        // either too many or not enough commas in rgb string
        return false;
    }

    return true;

}

// does math on a deciaml value to map it to its hex equivalent
std::string rgb_to_hex(std::string str){
    std::string hex_value = "#";
    std::string temp = "";

    std::map<int, char> decimal_hex_map = {
        {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}
    };

    // adding a comma at the end of the str just to be able make sure i get all parts between commas when iterating
    str += ',';

    // looping through entire string adding the current char to a temp var until we hit a comma
    for (const char& character : str){
        if (character != ','){
            temp += character;

        } else {
            int temp_int = std::stoi(temp);

            // finding integer and remainder values of current value when divided by 16
            int integer_part = temp_int / 16;
            int remainder_part = temp_int % 16;

            // mapping integer & remainder values to hex equivalents
            char first_part = decimal_hex_map.find(integer_part)->second;
            char second_part = decimal_hex_map.find(remainder_part)->second;

            // adding first and second part to hex_value
            hex_value += first_part;
            hex_value += second_part;

            // clearing temp for next iteration
            temp = "";
        }
    }

    return hex_value;
}
