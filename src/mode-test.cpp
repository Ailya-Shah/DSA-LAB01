#include <iostream>
#include "mode.h"

int main() {
    // Test 1: Array with unique mode
    std::vector<int> arr1 = {1, 2, 2, 3, 4};
    std::cout << "Test 1 (unique mode): " << findMode(arr1) << "\n"; 
    // expected output: 2

    // Test 2: Array with multiple modes
    std::vector<int> arr2 = {1, 1, 2, 2, 3};
    std::cout << "Test 2 (multiple modes): " << findMode(arr2) << "\n";
    // expected output: 1 or 2 (both correct since both occur 2 times)

    // Test 3: Empty array
    std::vector<int> arr3;
    std::cout << "Test 3 (empty array): " << findMode(arr3) << "\n";
    // expected output: -1

    return 0;
}
