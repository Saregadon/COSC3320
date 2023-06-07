#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/sysinfo.h>

int main() {    
    int *AR1 = NULL;
    int *AR2 = NULL;
    int *AR3 = NULL;
    int *Array1 = NULL;
    int *Array2 = NULL;
    int *Array3 = NULL;
    int m = 3; //how many arrays *3 you need to hold 1mb each
    struct timespec start, end;
    struct sysinfo sys_info;
    long long time;
    int count = 0;
    int elements = 0;

    if (sysinfo(&sys_info) == 0) {
        long long total_memory = sys_info.totalram * sys_info.mem_unit;
        long long free_memory = sys_info.freeram * sys_info.mem_unit;
        printf("Total memory: %lld bytes\n", total_memory);
        printf("Free memory: %lld bytes\n", free_memory);
    } else {
        printf("Failed to get system information.\n");
    }

    //time measurement for allocation of 3m arrays of size 1mb each;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while(1){
        //Malloc new element in AR1 in each element
        int* Array1 = (int*)malloc(sizeof(int));
        if(Array1 == NULL){ //no more memory for AR1
            break;
        } else count++;
        //Malloc new element in AR2 in each element
        int* Array2 = (int*)malloc(sizeof(int));
        if(Array2 == NULL){ //no more memory for AR2
            break;
        }else count++;
        //Malloc new element in AR3 in each element
        int* Array3 = (int*)malloc(sizeof(int));
        if(Array3 == NULL){ //no more memory for AR3
            break;
        }else count++;
    }

    AR1 = Array1;
    AR2 = Array2;
    AR3 = Array3;
    count++;

    free(Array1);
    free(Array2);
    free(Array3);

    printf("This was how many elements we had", count);

    clock_gettime(CLOCK_MONOTONIC, &end);
    time = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_sec - start.tv_sec);
    printf("Time elapsed for #1 -- the allocation of 3m arrays that have 1mb each.\n", time);

    time = 0;
    //time measurement for deallocation or #2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 1; i <= m; i+2){
        AR1[i];
        AR2[i];
        AR3[i];
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    time = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_sec - start.tv_sec);
    printf("Time elapsed for #2 -- the deallocation of even numbered arrays.\n", time);

    free(AR1);
    free(AR2);
    free(AR3);

    return 0;
}
