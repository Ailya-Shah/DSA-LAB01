#include "strassen.h"
#include <stdexcept>

// Helper: Add two matrices
Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Helper: Subtract two matrices
Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Naive O(n^3) multiplication
Matrix naiveMultiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Strassen algorithm
Matrix strassenMultiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 1) { // base case
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    Matrix a11(newSize, std::vector<int>(newSize));
    Matrix a12(newSize, std::vector<int>(newSize));
    Matrix a21(newSize, std::vector<int>(newSize));
    Matrix a22(newSize, std::vector<int>(newSize));
    Matrix b11(newSize, std::vector<int>(newSize));
    Matrix b12(newSize, std::vector<int>(newSize));
    Matrix b21(newSize, std::vector<int>(newSize));
    Matrix b22(newSize, std::vector<int>(newSize));

    // Split matrices into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Strassen’s 7 multiplications
    Matrix m1 = strassenMultiply(add(a11, a22), add(b11, b22));
    Matrix m2 = strassenMultiply(add(a21, a22), b11);
    Matrix m3 = strassenMultiply(a11, subtract(b12, b22));
    Matrix m4 = strassenMultiply(a22, subtract(b21, b11));
    Matrix m5 = strassenMultiply(add(a11, a12), b22);
    Matrix m6 = strassenMultiply(subtract(a21, a11), add(b11, b12));
    Matrix m7 = strassenMultiply(subtract(a12, a22), add(b21, b22));

    // Combine results into result matrix C
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j]             = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
            C[i][j + newSize]   = m3[i][j] + m5[i][j];
            C[i + newSize][j]   = m2[i][j] + m4[i][j];
            C[i + newSize][j + newSize] = m1[i][j] - m2[i][j] + m3[i][j] + m6[i][j];
        }
    }
    return C;
}
