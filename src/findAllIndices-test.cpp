#include <iostream>
#include "findAllIndices.h"
using namespace std;

int main() {
    // 1. Multiple occurrences
    vector<int> arr1 = {1, 2, 3, 2, 4, 2, 5};
    int key1 = 2;
    vector<int> result1 = findAllIndices(arr1, key1);
    cout << "Test Case 1 (Multiple occurrences): ";
    for (int idx : result1) cout << idx << " ";
    cout << endl;

    // 2. Key not present
    vector<int> arr2 = {10, 20, 30, 40};
    int key2 = 25;
    vector<int> result2 = findAllIndices(arr2, key2);
    cout << "Test Case 2 (Key not present): ";
    if (result2.empty()) cout << "No indices found";
    else for (int idx : result2) cout << idx << " ";
    cout << endl;

    // 3. Empty array
    vector<int> arr3 = {};
    int key3 = 5;
    vector<int> result3 = findAllIndices(arr3, key3);
    cout << "Test Case 3 (Empty array): ";
    if (result3.empty()) cout << "No indices found";
    else for (int idx : result3) cout << idx << " ";
    cout << endl;

    return 0;
}

