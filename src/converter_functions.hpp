// removes all the spaces within a string
std::string remove_spaces(const std::string& str);

// converts all the lower characters in a string to the uppercase version if possible
std::string upper_str(std::string& str);

// checks to see if an entire string is alnumeric
bool isalnum_str(const std::string& str);

// checks to see if all characters in string are hex characters
bool valid_hex_str(const std::string& str, const std::map<char, int>& hex_rgb_map);

// converts hex value into rgb value
std::map<char, int> hex_to_rgb(const std::string& str, const std::map<char, int>& hex_rgb_map);

// checking to see if str is a valid rgb str
bool valid_rgb_str(std::string str);

// does math on a deciaml value to map it to its hex equivalent
std::string rgb_to_hex(std::string str);