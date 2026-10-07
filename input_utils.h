#ifndef LAB1_INPUT_UTILS_H_
#define LAB1_INPUT_UTILS_H_

#include <iostream>
#include <string>

inline bool IsInputLineClean() {
    std::string remainder;
    std::getline(std::cin, remainder);
    return remainder.find_first_not_of(" \t\r") == std::string::npos;
}

#endif  // LAB1_INPUT_UTILS_H_
