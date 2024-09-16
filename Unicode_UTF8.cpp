#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <windows.h>

// Function to convert a Unicode code point to a UTF-8 string
std::string unicodeToUTF8(const std::string& unicode) {
    // Convert the Unicode code point to an integer
    unsigned int codePoint;
    std::stringstream ss;
    ss << std::hex << unicode.substr(2); // Skip the "U+"
    ss >> codePoint;

    // Convert the code point to a UTF-8 string
    std::string utf8;
    if (codePoint <= 0x7F) {
        utf8 += static_cast<char>(codePoint);
    } else if (codePoint <= 0x7FF) {
        utf8 += static_cast<char>((codePoint >> 6) | 0xC0);
        utf8 += static_cast<char>((codePoint & 0x3F) | 0x80);
    } else if (codePoint <= 0xFFFF) {
        utf8 += static_cast<char>((codePoint >> 12) | 0xE0);
        utf8 += static_cast<char>(((codePoint >> 6) & 0x3F) | 0x80);
        utf8 += static_cast<char>((codePoint & 0x3F) | 0x80);
    } else if (codePoint <= 0x10FFFF) {
        utf8 += static_cast<char>((codePoint >> 18) | 0xF0);
        utf8 += static_cast<char>(((codePoint >> 12) & 0x3F) | 0x80);
        utf8 += static_cast<char>(((codePoint >> 6) & 0x3F) | 0x80);
        utf8 += static_cast<char>((codePoint & 0x3F) | 0x80);
    }

    // Convert the UTF-8 string to hexadecimal escape sequences
    std::stringstream hexStream;
    for (unsigned char c : utf8) {
        hexStream << "\\x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    }

    return hexStream.str();
}

// Function to process an array of Unicode code points and convert them to UTF-8
std::vector<std::string> processUnicodeArray(const std::vector<std::string>& unicodeArray) {
    std::vector<std::string> utf8HexArray;

    for (const std::string& unicode : unicodeArray) {
        utf8HexArray.push_back(unicodeToUTF8(unicode));
    }

    return utf8HexArray;
}

int main() {
    // Set the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Example array of Unicode code points
    std::vector<std::string> unicodeArray = {"U+1F600", "U+1F601", "U+1F602"}; // Adding multiple Unicodes

    // Process the array of Unicode code points
    std::vector<std::string> utf8HexArray = processUnicodeArray(unicodeArray);

    // Display the UTF-8 hexadecimal escape sequences for each Unicode value
    for (size_t i = 0; i < unicodeArray.size(); ++i) {
        std::cout << "Unicode: " << unicodeArray[i] << " -> UTF-8 Hexadecimal Escape Sequence: " << utf8HexArray[i] << std::endl;
    }

    return 0;
}
