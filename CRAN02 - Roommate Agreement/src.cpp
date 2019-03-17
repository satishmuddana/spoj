#include <iostream>
#include <vector>
#include<map>
using namespace std;

/*
 *  Solved using Prefix Sum and Hash map
 */
long long int numOfZeroSequences(int* arr, int numElements) {
    long long int zeroSequences = 0;
    map<int, int> mapFrequencies;
    for (int i = 0; i < numElements; i++) {
        if (i > 0)
            arr[i] += arr[i-1];
        if (mapFrequencies.find(arr[i]) == mapFrequencies.end()) {
            mapFrequencies[arr[i]] = 1;
        }
        else {
            zeroSequences += mapFrequencies[arr[i]];
            mapFrequencies[arr[i]]++;
        }
        if (arr[i] == 0)
            zeroSequences++;
    }
    return zeroSequences;
}

int main() {
    int testCases   = 0,
        numElements = 0;
    cin >> testCases;
    while(testCases--) {
        cin >> numElements;
        int arr[numElements];
        for (int i = 0; i < numElements; i++) {
            cin >> arr[i];
        }
        cout << numOfZeroSequences(arr, numElements) << endl;
    }
    return 0;
}