import numpy as np
import time

# Function to measure the time taken for matrix addition

"""
    Perform matrix addition of two n x n matrices and measure the execution time.

    Parameters:
    - n: The size of the matrices.
    - version: The version of the matrix addition algorithm to use (1 or 2).

    Returns:
    - The execution time in seconds.
"""

def matrix_addition(n, version):
    A = np.random.rand(n, n)  # Initialize matrix A with random values
    B = np.random.rand(n, n)  # Initialize matrix B with random values
    C = np.zeros((n, n))      # Initialize matrix C with zeros

    start_time = time.time()

    if version == 1:
        for i in range(n):
            for j in range(n):
                C[i, j] = A[i, j] + B[i, j]
    elif version == 2:
        for j in range(n):
            for i in range(n):
                C[i, j] = A[i, j] + B[i, j]

    end_time = time.time()
    return end_time - start_time

# Sequence of values for n
sequence = [128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536]

# Measure timings for both versions
for n in sequence:
    time_version_1 = matrix_addition(n, 1)
    time_version_2 = matrix_addition(n, 2)
    print(f"n = {n}, Version 1 time = {time_version_1}, Version 2 time = {time_version_2}")

#run using
#python -u Assignment4.py
#python3 -u Assignment4.py - wsl

#Timing 
"""
The code measures the execution time of two versions of matrix addition algorithm for different 
matrix sizes. It generates random matrices A and B of size n x n, initializes matrix C with zeros, 
and then performs the matrix addition using either version 1 or version 2. The execution time is 
measured using the time.time() function before and after the matrix addition, and the difference 
is calculated.

The matrix_addition function takes two parameters: n for the matrix size and version to determine 
which algorithm version to use. It returns the execution time in seconds.

The sequence list defines the values of n for which the timings will be measured. The code then 
iterates over this sequence, calls the matrix_addition function for both versions, and prints the results.

Assignment 4 Notes

Note - THAT EVERYTHING IS IN SECONDS

n = 128, Version 1 time = 0.00435638427734375, Version 2 time = 0.0042002201080322266
n = 256, Version 1 time = 0.01934814453125, Version 2 time = 0.01830458641052246
n = 512, Version 1 time = 0.07316088676452637, Version 2 time = 0.07638120651245117
n = 1024, Version 1 time = 0.29168248176574707, Version 2 time = 0.40419745445251465
n = 2048, Version 1 time = 1.1686546802520752, Version 2 time = 1.7977614402770996
n = 4096, Version 1 time = 4.697006464004517, Version 2 time = 7.052334308624268
n = 8192, Version 1 time = 18.970118761062622, Version 2 time = 28.37813973426819
n = 16384, Version 1 time = 75.34112977981567, Version 2 time = 116.23827624320984
n = 32768, Version 1 time = 306.2558307647705, Version 2 time = 657.3897912502289

Run 2
n = 128, Version 1 time = 0.0044901371002197266, Version 2 time = 0.004387855529785156
n = 256, Version 1 time = 0.01791524887084961, Version 2 time = 0.018084049224853516
n = 512, Version 1 time = 0.07451748847961426, Version 2 time = 0.08118438720703125
n = 1024, Version 1 time = 0.2920260429382324, Version 2 time = 0.41611385345458984
n = 2048, Version 1 time = 1.1737470626831055, Version 2 time = 1.7096195220947266
n = 4096, Version 1 time = 4.789830923080444, Version 2 time = 6.918642997741699
n = 8192, Version 1 time = 18.919447422027588, Version 2 time = 27.63094449043274
n = 16384, Version 1 time = 76.12821388244629, Version 2 time = 111.71175122261047
n = 32768, Version 1 time = 304.8916037082672, Version 2 time = 547.7969162464142

Run 3
n = 128, Version 1 time = 0.004434823989868164, Version 2 time = 0.004378080368041992
n = 256, Version 1 time = 0.01803445816040039, Version 2 time = 0.018113374710083008
n = 512, Version 1 time = 0.07565569877624512, Version 2 time = 0.0820000171661377
n = 1024, Version 1 time = 0.293764591217041, Version 2 time = 0.4276130199432373
n = 2048, Version 1 time = 1.1761465072631836, Version 2 time = 1.7011590003967285
n = 4096, Version 1 time = 4.734057426452637, Version 2 time = 6.901985168457031
n = 8192, Version 1 time = 19.026060581207275, Version 2 time = 27.722479343414307
n = 16384, Version 1 time = 76.27064728736877, Version 2 time = 131.99759316444397
n = 32768, Version 1 time = 306.81384348869324, Version 2 time = 712.4329967498779

Matrix Initialization: The code initializes three matrices A, B, and C with size n x n. Initializing 
each element of the matrices has a time complexity of O(1). Therefore, the time complexity of matrix 
initialization is O(n^2).
Matrix Addition: The code performs matrix addition using two nested loops. For each element in the matrices 
A and B, it performs a single addition operation. Since there are n x n elements in total, the time complexity 
of matrix addition is O(n^2).
Timing Measurements: The code measures the execution time of each matrix addition operation using the time.time() 
function. The time complexity of timing measurements is negligible compared to the matrix addition operations.
Iterating Over Sequence: The code iterates over the sequence of values for n. Since the sequence has a fixed 
length, the time complexity of this part is O(1).
Overall, the time complexity of the code can be expressed as O(n^2), where n is the size of the matrices.
As for the space complexity, the code initializes three matrices A, B, and C, each with size n x n. Therefore, 
the space complexity is O(n^2) to store the matrices.
Note that the numpy library is used for matrix operations, which internally utilizes optimized routines and 
data structures. The space complexity may also depend on the internal memory management of numpy, but it is 
still dominated by the size of the matrices, which is O(n^2).
"""