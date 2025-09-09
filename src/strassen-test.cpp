#include <iostream>
#include "strassen.h"

// Helper to print matrix
void printMatrix(const Matrix& M) {
    for (auto& row : M) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    // Test 1: 2x2 matrices
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};
    Matrix result1 = strassenMultiply(A, B);
    std::cout << "Test 1 (2x2 Strassen result):\n";
    printMatrix(result1);

    // Test 2: 4x4 matrices
    Matrix C = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Matrix D = {{16,15,14,13},{12,11,10,9},{8,7,6,5},{4,3,2,1}};
    Matrix result2 = strassenMultiply(C, D);
    std::cout << "Test 2 (4x4 Strassen result):\n";
    printMatrix(result2);

    // Test 3: Random matrix vs Naive multiplication
    Matrix E = {{2,3},{1,4}};
    Matrix F = {{0,1},{5,2}};
    Matrix strassenRes = strassenMultiply(E, F);
    Matrix naiveRes = naiveMultiply(E, F);

    std::cout << "Test 3 (compare with naive):\n";
    std::cout << "Strassen:\n"; printMatrix(strassenRes);
    std::cout << "Naive:\n"; printMatrix(naiveRes);

    return 0;
}
