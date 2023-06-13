#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rlimit mem_limit;
    getrlimit(RLIMIT_AS, &mem_limit);
    long long available_memory = mem_limit.rlim_cur / 3;  // Divide by 3 for each array
    int** AR1 = NULL;
    int** AR2 = NULL;
    int** AR3 = NULL;
    int** AR4 = NULL;
    int* newElementAR1 = NULL;
    int* newElementAR2 = NULL;
    int* newElementAR3 = NULL;

    int element_size = 1024 * 1024;  // 1MB
    struct timeval start, end;
    long long elapsed_micros, elapsed_seconds, elapsed_milliseconds;

    gettimeofday(&start, NULL);
    int count = 0;
    while (count < 130001) { // 130000*3 = m = 390,000
      if (available_memory < element_size) break;
        int* Array1 = (int*)malloc(element_size);
      if(Array1 == NULL) break;
        int* Array2 = (int*)malloc(element_size);
      if(Array2 == NULL) break;
        int* Array3 = (int*)malloc(element_size);
      if(Array3 == NULL) break;
        AR1 = (int**)realloc(AR1, (count + 1) * sizeof(int*));
        AR2 = (int**)realloc(AR2, (count + 1) * sizeof(int*));
        AR3 = (int**)realloc(AR3, (count + 1) * sizeof(int*));
        AR1[count] = Array1;
        AR2[count] = Array2;
        AR3[count] = Array3;
        count++;
        //printf("Number of elements in AR1, AR2, AR3: %d\n", count);
        available_memory -= element_size;
    }
    gettimeofday(&end, NULL);
    elapsed_micros = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec); //microseconds
    elapsed_seconds = elapsed_micros / 1000000; // seconds
    printf("Time taken for initial allocation: %lld seconds\n", elapsed_seconds);
    printf("Number of elements in AR1, AR2, AR3: %d\n", count);
    gettimeofday(&start, NULL);
    for (int i = 0; i < count; i += 2) {
        free(AR1[i]);
        free(AR2[i]);
        free(AR3[i]);
    }
    gettimeofday(&end, NULL);
    elapsed_micros = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
    elapsed_milliseconds = elapsed_micros / 1000; // milliseconds
    printf("Time taken for deallocation of even number elements: %lld milliseconds\n", elapsed_milliseconds);

    gettimeofday(&start, NULL);
    int** tempAR4 = NULL;
    int ar4_count = 0;
    int ar4_element_size = 1024 * 1024 * 1.25;  // 1.25MB
    while (ar4_count < 13000) {
        if (available_memory < ar4_element_size)
            break;
        int* newElementAR4 = (int*)malloc(ar4_element_size);
        if (newElementAR4 == NULL)
            break;
        tempAR4 = (int**)realloc(tempAR4, (ar4_count + 1) * sizeof(int*));
        tempAR4[ar4_count] = newElementAR4;
        ar4_count++;
        available_memory -= ar4_element_size;
        //printf("Number of elements in AR4: %d\n", ar4_count);
    }
    AR4 = tempAR4;
    gettimeofday(&end, NULL);
    elapsed_micros = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
    elapsed_seconds = elapsed_micros / 1000000; // seconds
    printf("Time taken for allocation to AR4: %lld seconds\n", elapsed_seconds);
    printf("Number of elements in AR4: %d\n", ar4_count);

    for (int i = count-2; i >= 0; i-=2) { //now frees odd memory
        free(AR1[i]);
        free(AR2[i]);
        free(AR3[i]);
    }
    free(AR1);
    free(AR2);
    free(AR3);

    for (int i = 0; i < ar4_count; i++) { //frees all of AR4 memory
        free(AR4[i]);
    }
    free(AR4);

    return 0;
}

/*
DATA STRUCTURES USED - Pointers, Arrays

The code measures the time taken for memory allocation and deallocation operations using dynamic memory allocation 
(malloc) and reallocation (realloc) in C.

The getrlimit function retrieves the current memory limit, and the available memory is calculated by dividing it by 
3 to allocate memory for three arrays: AR1, AR2, and AR3.

The code uses malloc to allocate memory blocks of size element_size (1MB) for Array1, Array2, and Array3. It then 
uses realloc to resize the arrays AR1, AR2, and AR3 to hold the newly allocated memory blocks. This process is 
repeated until either the available memory is insufficient or the count reaches 130,001. (130,001 was used for AR1,
AR2, and AR3 because it's what my machine on my computer at home can handle).

After the initial allocation, the code measures the time taken for deallocation by freeing memory for every 
even-indexed element in AR1, AR2, and AR3.

Next, the code allocates memory for AR4 using malloc for an element size of ar4_element_size (1.25MB). It keeps track 
of the count and the available memory. This process is repeated until either the available memory is insufficient 
or the count reaches 13,000. (13,000 being used for AR4 is what my machine on my computer at home can handle).

Finally, the code frees the odd-indexed memory in AR1, AR2, and AR3 and frees all the memory blocks in AR4. It also 
frees the arrays AR1, AR2, AR3, and AR4.

Time Complexity - 
Initial Allocation: The while loop iterates until the count reaches 130,001 or the available memory is insufficient. 
Inside the loop, memory allocation (malloc) and reallocation (realloc) operations are performed. Both malloc and 
realloc have a time complexity of O(1) on average. Therefore, the time complexity of this section is O(n), where n 
is the number of iterations in the loop.
Deallocation of Even-Indexed Elements: The for loop iterates over the even-indexed elements of AR1, AR2, and AR3 
and performs memory deallocation (free). The time complexity of the deallocation operation (free) is O(1). Therefore, 
the time complexity of this section is O(m), where m is the number of even-indexed elements.
Allocation to AR4: The while loop iterates until the ar4_count reaches 13,000 or the available memory is insufficient. 
Inside the loop, memory allocation (malloc) and reallocation (realloc) operations are performed. Again, both malloc and 
realloc have a time complexity of O(1) on average. Therefore, the time complexity of this section is O(k), where k is 
the number of iterations in the loop.
Deallocating Odd-Indexed Elements and Freeing Memory: The for loop iterates over the odd-indexed elements of AR1, AR2, 
and AR3, and another for loop iterates over the elements of AR4, performing memory deallocation (free). The time 
complexity of the deallocation operation (free) is O(1). Therefore, the time complexity of this section is O(p + q), 
where p is the number of odd-indexed elements in AR1, AR2, and AR3, and q is the number of elements in AR4.
Overall, the time complexity of the code can be expressed as O(n + m + k + p + q).
As for the space complexity, the code uses dynamic memory allocation to allocate and deallocate memory blocks. The 
space complexity mainly depends on the maximum number of memory blocks allocated simultaneously, which is determined 
by the available memory and the element sizes.
In this code, there are four arrays: AR1, AR2, AR3, and AR4. The space complexity is determined by the total size of 
these arrays and the memory blocks they hold. The size of each memory block is element_size or ar4_element_size, and 
the number of blocks is determined by the respective counts (count and ar4_count).
Therefore, the space complexity of the code can be expressed as O(count * element_size + ar4_count * ar4_element_size),
 where count is the number of elements in AR1, AR2, and AR3, and ar4_count is the number of elements in AR4.
Note that the actual space usage may also depend on the implementation details of the memory allocation functions 
(malloc, realloc, free) and the underlying memory management system.

OUTPUT FOR RUN 1:
Time taken for initial allocation: 22 seconds
Number of elements in AR1, AR2, AR3: 130001
Time taken for deallocation of even number elements: 181 milliseconds
Time taken for allocation to AR4: 177 seconds
Number of elements in AR4: 13000

OUTPUT FOR RUN 2:
Time taken for initial allocation: 17 seconds
Number of elements in AR1, AR2, AR3: 130001
Time taken for deallocation of even number elements: 147 milliseconds
Time taken for allocation to AR4: 171 seconds
Number of elements in AR4: 13000

OUTPUT FOR RUN 3:
Time taken for initial allocation: 17 seconds
Number of elements in AR1, AR2, AR3: 130001
Time taken for deallocation of even number elements: 140 milliseconds
Time taken for allocation to AR4: 170 seconds
Number of elements in AR4: 13000

To compile and run the code, you can use the following commands:
gcc Assignment5.c -o Assignment
./Assignment

*/