#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

// Function to fill the array with random values
void fill(vector<int>& arr);

// Binary search function
int binarySearch(const std::vector<int>& arr, int target);

int main() {
    // Initialize arrays of varying sizes
    vector<vector<int>> arrays = {{100}, {200}, {400}, {800}, {1600}, {3200},
                                  {6400}, {12800}, {25600}, {51200}};

    int index = 0;
    int target = 2147483647;

    vector<milliseconds> durations(arrays.size());

    // Perform binary search on each array and measure the execution time
    for (int i = 0; i < arrays.size(); i++) {
        vector<int>& arr = arrays[i];
        auto start = high_resolution_clock::now();
        for (int j = 0; j < 10000000; j++)
            index = binarySearch(arr, target);
        auto end = high_resolution_clock::now();
        durations[i] = duration_cast<milliseconds>(end - start);
    }

    // Output the durations
    for (int i = 0; i < arrays.size(); i++) {
        cout << "Time " << i + 1 << ": " << durations[i].count() << " milliseconds" << endl;
    }

    return 0;
}

void fill(vector<int>& arr){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1000);
    for (int i = 0; i < arr.size(); i++){
        arr[i] = dis(gen);
    }
}

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

/*
DATA STRUCTURES USED - Vectors, vector of vectors

The given code performs binary search on different arrays of varying sizes and measures the 
execution time for each search operation. The code uses the binarySearch function to perform 
the binary search algorithm. It initializes a vector of vectors (arrays) to hold the different 
arrays to be searched. The code then iterates over each array, performs 10,000,000 unsuccessful 
search operations, and records the duration of each search. The durations are stored in a 
separate vector (durations) and finally displayed on the console.

Time Complexity:
The time complexity of the binary search algorithm is O(log n), where n is the size of the 
input array. In this code, binary search is performed 10,000,000 times for each array in the 
arrays vector. Therefore, the time complexity of the code is O(10,000,000 * log n), where n 
represents the size of each array.

Space Complexity:
The space complexity of the code is determined by the space used to store the arrays and the 
durations vector. The space required for the arrays is proportional to the total number of 
elements across all arrays. The space required for the durations vector is proportional to 
the number of arrays. Therefore, the space complexity can be considered as O(N), where N is 
the total number of elements across all arrays plus the number of arrays

Run 1::
Time 1: 89 milliseconds
Time 2: 89 milliseconds
Time 3: 89 milliseconds
Time 4: 88 milliseconds
Time 5: 88 milliseconds
Time 6: 90 milliseconds
Time 7: 90 milliseconds
Time 8: 89 milliseconds
Time 9: 89 milliseconds
Time 10: 91 milliseconds

Run 2::
Time 1: 91 milliseconds
Time 2: 91 milliseconds
Time 3: 91 milliseconds
Time 4: 89 milliseconds
Time 5: 97 milliseconds
Time 6: 109 milliseconds
Time 7: 97 milliseconds
Time 8: 96 milliseconds
Time 9: 89 milliseconds
Time 10: 97 milliseconds

Run 3::
Time 1: 89 milliseconds
Time 2: 89 milliseconds
Time 3: 95 milliseconds
Time 4: 91 milliseconds
Time 5: 88 milliseconds
Time 6: 88 milliseconds
Time 7: 94 milliseconds
Time 8: 90 milliseconds
Time 9: 89 milliseconds
Time 10: 91 milliseconds
*/