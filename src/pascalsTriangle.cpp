#include "pascalsTriangle.h"

std::vector<std::vector<int>> generatePascalsTriangle(int n) {
    std::vector<std::vector<int>> triangle;

    for (int row = 0; row < n; row++) {
        std::vector<int> currentRow(row + 1, 1); // initialize with 1s

        for (int col = 1; col < row; col++) {
            currentRow[col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
        }

        triangle.push_back(currentRow);
    }

    return triangle;
}
