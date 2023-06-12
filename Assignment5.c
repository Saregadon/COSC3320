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
    long long elapsed_micros, elapsed_seconds;

    gettimeofday(&start, NULL);
    int count = 0;
    while (count < 130001) { // 130000 = m
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
    elapsed_seconds = elapsed_micros / 1000000; // seconds
    printf("Time taken for deallocation of even number elements: %lld seconds\n", elapsed_seconds);

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
//gcc Assignment5.c -o Assignment
// ./Assignment