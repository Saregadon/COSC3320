#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

//now for the sorting to actually begin
int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[start]; //pivot = x
    int i = start + 1;
    int j = end;
    
    while (true) {
        while (i <= j && arr[i] <= pivot)
            i++;
        
        while (i <= j && arr[j] > pivot)
            j--;
        
        if (i > j)
            break;
        
        swap(arr[i], arr[j]);
    }
    
    swap(arr[start], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main() {
    int n = 1000;
    vector<int> arr(n);

    // Generate random numbers for the array
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1000);
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }

    //sort(arr.begin(), arr.end()); // Sort the array in ascending order to make the worst case which is O(n^2)
                                  // Delete to have average case of O(n*logn)
    time_point<steady_clock> start, end;
    start = steady_clock::now();
    quickSort(arr, 0, n-1);
    end = steady_clock::now();
    duration<double, nano> elapsed_time = end - start;

    cout << "Time: " << elapsed_time.count() << " nanoseconds" << endl;

    return 0;
}
/*use 
g++ Assignment3.cpp -o Assignment && ./Assignment 
to run the code */
/*
Hypothesis - The sort algorithm will have an extremely fast time and space complexity,
however I want to see how it works given that it is described as a less than reputable
sorting algorithm by Professor Leiss.

Conclusion - It is a fast algorithm only when it is not previously sorted. If the numbers
are random and they are already sorted. Then the algorithm quickly turns into an extremely
slow moving sorting algorithm.

DATA STRUCTURES USED - Vectors, Number engine generator, uniiform distribution oject

The provided code implements the QuickSort algorithm to sort a vector of integers. 
It uses the partition function to choose a pivot element and rearrange the elements 
in the vector such that all elements smaller than the pivot are placed before it and 
all elements greater than the pivot are placed after it. The quickSort function 
recursively calls itself to sort the subarrays on the left and right of the pivot.

When the input array is already sorted (either in ascending or descending order) or 
contains many elements with the same value.
In such cases, if the pivot selection and partitioning strategy are not optimized, 
the partitioning step can create highly unbalanced partitions. If the pivot consistently selects 
the smallest or largest element, the partitioning will not divide the array evenly, leading to one 
partition significantly larger than the other.

Time Complexity - 
As a result, the recursion depth becomes equal to the size of the input array, and each recursive 
call processes a reduced portion of the input array by only one element at a time. This scenario 
leads to an overall time complexity of O(n^2), as each element needs to be compared and moved 
multiple times.

It's important to note that the code I provided does not include any specific optimizations for 
pivot selection or partitioning strategy, which can contribute to the worst-case time complexity. 
However, in practice, randomized pivot selection or other techniques can be employed to mitigate 
the chances of encountering the worst-case scenario and achieve better average-case or expected 
time complexity of O(n log n).

Space Complexity -
The space complexity of the given code is O(log n) in the worst case, where n is the number of 
elements in the array. This space complexity arises from the recursive calls made in the quickSort 
function.

In the quickSort function, the recursive calls are made for two subproblems, each with approximately 
half the size of the original problem. This means that in the worst case, the maximum depth of 
the recursion would be log n.

At each level of the recursion, a constant amount of additional space is used for the variables 
pivotIndex, start, and end. Therefore, the space required for each level of recursion is constant. 
Since the maximum depth of the recursion is log n, the overall space complexity is O(log n).

//O(n log n)
//Timing 1
Time: 0 nanoseconds
//Timing 2
Time: 1.003e+006 nanoseconds
//Timing 3
Time: 0 nanoseconds

//O(n^2) //uncomment the sort mechanic
//Timing 1
Time: 1.001e+006 nanoseconds
//Timing 2
Time: 979000 nanoseconds
//Timing 3
Time: 1.004e+006 nanoseconds
*/