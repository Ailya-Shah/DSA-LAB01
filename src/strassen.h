#ifndef STRASSEN_H
#define STRASSEN_H

#include <vector>

// Define matrix as a vector of vector<int>
using Matrix = std::vector<std::vector<int>>;

// Function declarations
Matrix naiveMultiply(const Matrix& A, const Matrix& B);
Matrix strassenMultiply(const Matrix& A, const Matrix& B);

#endif // STRASSEN_H
