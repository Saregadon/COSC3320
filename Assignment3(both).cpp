#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

class InfiniteSequence {
private:
    int current;

public:
    InfiniteSequence() : current(1) {}

    int next() {
        return ++current;
    }
};

void assignFastest(vector<int>& arr, int start, int end, InfiniteSequence& sequence) {
    vector<pair<int, int>> fast;
    fast.push_back(make_pair(start, end));

    while (!fast.empty()) {
        int start = fast.back().first;
        int end = fast.back().second;
        fast.pop_back();

        if (start > end)
            continue;

        int mid = (start + end) / 2;
        arr[mid] = sequence.next();  // Assign the next number to the middle element

        fast.push_back(make_pair(start, mid - 1));
        fast.push_back(make_pair(mid + 1, end));
    }
}

void assignSlowest(vector<int>& arr, int start, int end, InfiniteSequence& sequence) {
    if (start > end)
        return;

    arr[start] = sequence.next();  // Assign the next number to the first element

    assignSlowest(arr, start + 1, end, sequence);
}

int main() {
    InfiniteSequence sequence;

    int n = 10000;  // Choose the value of n
    vector<int> arr(n);

    // Measure the execution time for fastest execution
    auto startFastest = high_resolution_clock::now();
    assignFastest(arr, 0, n - 1, sequence);
    auto stopFastest = high_resolution_clock::now();
    auto durationFastest = duration_cast<nanoseconds>(stopFastest - startFastest);

    // Print the assigned array for fastest execution
    cout << "Fastest Execution: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Fastest Execution Time: " << durationFastest.count() << " nanoseconds" << endl;

    // Reset the sequence
    sequence = InfiniteSequence();

    // Measure the execution time for slowest execution
    auto startSlowest = high_resolution_clock::now();
    assignSlowest(arr, 0, n - 1, sequence);
    auto stopSlowest = high_resolution_clock::now();
    auto durationSlowest = duration_cast<nanoseconds>(stopSlowest - startSlowest);

    // Print the assigned array for slowest execution
    cout << "Slowest Execution: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Slowest Execution Time: " << durationSlowest.count() << " nanoseconds" << endl;

    return 0;
}
