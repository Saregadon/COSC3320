import random
import time

def fill(arr): #initialize arrays
    for i in range(len(arr)):
        arr[i] = random.randint(1, 1000)

def binary_search(arr, target): #binary search function
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

arrays = [[100], [200], [400], [800], [1600], [3200],
          [6400], [12800], [25600], [51200]] #all arrays doubling until 51200

target = 2147483647 #target that we won't find

durations = []

for arr in arrays: #main
    fill(arr)
    start = time.perf_counter()
    for _ in range(10000000):
        index = binary_search(arr, target)
    end = time.perf_counter()
    durations.append((end - start))  # In seconds

for i, duration in enumerate(durations):
    print(f"Time {i + 1}: {duration} seconds")

"""
DATA STRUCTURES USED - Lists

The given code performs binary search on different arrays of varying sizes and measures 
the execution time for each search operation. It uses the fill function to initialize 
the arrays with random values and the binary_search function to perform the binary search 
algorithm. The arrays are defined as a list of lists (arrays), where each inner list 
represents an array with a specific size. The code iterates over each array, performs 
10,000,000 search operations for each array, and records the duration of each search. 
The durations are stored in a separate list (durations) and then displayed on the console.

Time Complexity:
The time complexity of the binary search algorithm is O(log n), where n is the size of the 
input array. In this code, binary search is performed 10,000,000 times for each array in the 
arrays list. Therefore, the time complexity of the code is O(10,000,000 * log n), where n 
represents the size of each array.

Space Complexity:
The space complexity of the code is determined by the space used to store the arrays and 
the durations list. The space required for the arrays is proportional to the total number 
of elements across all arrays. The space required for the durations list is proportional 
to the number of arrays. Therefore, the space complexity can be considered as O(N), where 
N is the total number of elements across all arrays plus the number of arrays.

Run 1::
Time 1: 4.6877584 seconds
Time 2: 4.8131024 seconds
Time 3: 4.7948068 seconds
Time 4: 4.866584999999999 seconds
Time 5: 4.7196494000000015 seconds
Time 6: 4.6712983 seconds
Time 7: 4.765804000000003 seconds
Time 8: 4.740078799999999 seconds
Time 9: 4.805248899999995 seconds
Time 10: 4.699169300000001 seconds

Run2::
Time 1: 4.7471711 seconds
Time 2: 4.8277282999999995 seconds
Time 3: 4.757702399999999 seconds
Time 4: 4.861356799999999 seconds
Time 5: 4.986174000000002 seconds
Time 6: 4.759046100000003 seconds
Time 7: 4.805968200000002 seconds
Time 8: 4.853549100000002 seconds
Time 9: 4.789194599999995 seconds
Time 10: 4.840418200000002 seconds

Run3::
Time 1: 4.8334048 seconds
Time 2: 4.7744188 seconds
Time 3: 4.8920178 seconds
Time 4: 4.7807466000000005 seconds
Time 5: 4.808437699999999 seconds
Time 6: 5.002357700000001 seconds
Time 7: 4.862001900000003 seconds
Time 8: 4.741033300000005 seconds
Time 9: 4.766355500000003 seconds
Time 10: 4.8410054 seconds
"""