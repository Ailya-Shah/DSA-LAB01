#include "mode.h"
#include <unordered_map> // for frequency counting
#include <limits>        // for INT_MIN

int findMode(const std::vector<int>& arr) {
    if (arr.empty()) return -1;   // handle empty case

    std::unordered_map<int, int> freq;  // maps element -> count
    for (int num : arr) {
        freq[num]++;
    }

    int mode = arr[0];
    int maxCount = 0;

    for (auto& p : freq) {
        if (p.second > maxCount) {
            maxCount = p.second;
            mode = p.first;
        }
    }

    return mode;
}
