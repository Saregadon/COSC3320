#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rlimit mem_limit; //call for memory limit
    getrlimit(RLIMIT_AS, &mem_limit); //call for memory limit
    long available_memory = mem_limit.rlim_cur / 3;  // Divide by 3 for each array
    int** AR1 = NULL;
    int** AR2 = NULL;
    int** AR3 = NULL;
    int** AR4 = NULL;
    int element_size = 1024 * 1024;  // 1MB
    struct timeval start, end;
    long long elapsed_micros; //measure of time

    gettimeofday(&start, NULL);
    int count = 0;
    while (1) {
        if (available_memory < element_size)
            break;
        int* newElementAR1 = (int*)malloc(element_size);
        int* newElementAR2 = (int*)malloc(element_size);
        int* newElementAR3 = (int*)malloc(element_size);
        if (newElementAR1 == NULL || newElementAR2 == NULL || newElementAR3 == NULL)
            break;
        AR1 = (int**)realloc(AR1, (count + 1) * sizeof(int*));
        AR2 = (int**)realloc(AR2, (count + 1) * sizeof(int*));
        AR3 = (int**)realloc(AR3, (count + 1) * sizeof(int*));
        AR1[count] = newElementAR1;
        AR2[count] = newElementAR2;
        AR3[count] = newElementAR3;
        count++;
        available_memory -= element_size;
    }
    gettimeofday(&end, NULL);
    elapsed_micros = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec); //microseconds
    printf("Time taken for initial allocation: %lld microseconds\n", elapsed_micros);
    printf("Number of elements in AR1, AR2, AR3: %d\n", count);
    gettimeofday(&start, NULL);
    for (int i = 0; i < count; i += 2) {
        free(AR1[i]);
        free(AR2[i]);
        free(AR3[i]);
    }
    gettimeofday(&end, NULL);
    elapsed_micros = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
    printf("Time taken for deallocation of even number elements: %lld microseconds\n", elapsed_micros);

    gettimeofday(&start, NULL);
    int** tempAR4 = NULL;
    int ar4_count = 0;
    int ar4_element_size = 1024 * 1024 * 1.25;  // 1.25MB
    while (1) {
        if (available_memory < ar4_element_size)
            break;
        int* newElementAR4 = (int*)malloc(ar4_element_size);
        if (newElementAR4 == NULL)
            break;
        tempAR4 = (int**)realloc(tempAR4, (ar4_count + 1) * sizeof(int*));
        tempAR4[ar4_count] = newElementAR4;
        ar4_count++;
        available_memory -= ar4_element_size;
    }
    AR4 = tempAR4;
    gettimeofday(&end, NULL);
    elapsed_micros = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
    printf("Time taken for allocation to AR4: %lld microseconds\n", elapsed_micros);
    printf("Number of elements in AR4: %d\n", ar4_count);

    for (int i = 0; i < count; i++) {
        free(AR1[i]);
        free(AR2[i]);
        free(AR3[i]);
    }
    free(AR1);
    free(AR2);
    free(AR3);

    for (int i = 0; i < ar4_count; i++) {
        free(AR4[i]);
    }
    free(AR4);

    return 0;
}