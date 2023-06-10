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
