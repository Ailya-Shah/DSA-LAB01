#include <iostream>
#include "pascalsTriangle.h"

void printTriangle(const std::vector<std::vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // === Test Case 1: n = 0 ===
    std::cout << "Test Case 1: n = 0" << std::endl;
    auto t1 = generatePascalsTriangle(0);
    printTriangle(t1);

    // === Test Case 2: n = 1 ===
    std::cout << "Test Case 2: n = 1" << std::endl;
    auto t2 = generatePascalsTriangle(1);
    printTriangle(t2);

    // === Test Case 3: n = 5 ===
    std::cout << "Test Case 3: n = 5" << std::endl;
    auto t3 = generatePascalsTriangle(5);
    printTriangle(t3);

    // === Verify row 5 → {1, 4, 6, 4, 1} ===
    std::cout << "Verifying row 5: ";
    for (int val : t3[4]) { // row 5 is index 4
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
