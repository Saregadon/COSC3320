#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int split(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);

    return i + 1;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end) {
        int pivotIndex = split(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main()
{
    int arr[] = {9, 3, 4, 2, 1, 8, 7, 5, 4, 6, 2, 13, 12, 11, 16, 91, 83, 40, 65, 73, 201};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Time measurement start
    auto start = high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    // Time measurement stop
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken: " << duration.count() << " nanoseconds." << endl;

    return 0;
}
