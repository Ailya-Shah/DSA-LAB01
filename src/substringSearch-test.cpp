#include <iostream>
#include "substringSearch.h"

int main() {
    // 1. Pattern at the beginning
    std::string text1 = "hello world";
    std::string pattern1 = "hello";
    std::cout << "Test 1 (Pattern at beginning): " 
              << findSubstring(text1, pattern1) << std::endl;

    // 2. Pattern at the end
    std::string text2 = "good morning";
    std::string pattern2 = "morning";
    std::cout << "Test 2 (Pattern at end): " 
              << findSubstring(text2, pattern2) << std::endl;

    // 3. Pattern not present
    std::string text3 = "abcdef";
    std::string pattern3 = "gh";
    std::cout << "Test 3 (Pattern not present): " 
              << findSubstring(text3, pattern3) << std::endl;

    // 4. Empty pattern
    std::string text4 = "sample";
    std::string pattern4 = "";
    std::cout << "Test 4 (Empty pattern): " 
              << findSubstring(text4, pattern4) << std::endl;

    return 0;
}
