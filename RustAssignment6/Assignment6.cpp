#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

void fill(vector<int>& arr); //prototype of fill array

// Binary search function
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> arrays = {{100}, {200}, {400}, {800}, {1600}, {3200},
                                  {6400}, {12800}, {25600}, {51200}}; //vector initializations

    int index = 0;
    int target = 2147483647;

    vector<nanoseconds> durations(arrays.size());

    for (int i = 0; i < arrays.size(); i++) {
        vector<int>& arr = arrays[i];
        auto start = high_resolution_clock::now();
        for (int j = 0; j < 10000000; j++) //10,000,000 unsuccessful searches
            index = binarySearch(arr, target);
        auto end = high_resolution_clock::now();
        durations[i] = duration_cast<nanoseconds>(end - start);
    }

    for (int i = 0; i < arrays.size(); i++) { //output durations
        cout << "Time " << i + 1 << ": " << durations[i].count() << " nanoseconds" << endl;
    }

    return 0;
}

void fill(vector<int>& arr){ //initialize vectors
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1000);
    for (int i = 0; i < arr.size(); i++){
        arr[i] = dis(gen);
    }
}