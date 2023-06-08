import numpy as np
import time

# Function to measure the time taken for matrix addition
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