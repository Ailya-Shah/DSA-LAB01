#include "substringSearch.h"

int findSubstring(const std::string& text, const std::string& pattern) {
    if (pattern.empty()) return 0;  // convention: empty pattern found at index 0

    int n = text.size();
    int m = pattern.size();

    if (m > n) return -1; // pattern longer than text → impossible

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) return i; // full match
    }

    return -1; // not found
}
