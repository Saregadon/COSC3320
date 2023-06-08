#include <iostream>

const int PAGE_SIZE = 2000;
const int ACTIVE_MEMORY_SET_SIZE = 1000;
const int ARRAY_SIZE = 4000;

void rowMajorOrder() {
    int numReads = 0;
    int numWrites = 0;
    int numPageReads = 0;
    int numPageWrites = 0;

    for (int I = 1; I <= ARRAY_SIZE; I++) {
        for (int J = 1; J <= ARRAY_SIZE; J++) {
            int pageIndex = (I - 1) / PAGE_SIZE;
            
            // Check if the page is not in the active memory set
            if (pageIndex >= ACTIVE_MEMORY_SET_SIZE) {
                numPageReads++;
            }
            numReads++;

            numWrites++;
            if (pageIndex >= ACTIVE_MEMORY_SET_SIZE) { //checks if page is in memory set
                numPageWrites++;
            }
        }
    }

    int numDiskReads = numPageReads / PAGE_SIZE;
    int numDiskWrites = numPageWrites / PAGE_SIZE;

    std::cout << "Row Major Order:\n";
    std::cout << "Number of Disk Reads: " << numDiskReads << "\n";
    std::cout << "Number of Disk Writes: " << numDiskWrites << "\n";
}

void columnMajorOrder() {
    int numReads = 0;
    int numWrites = 0;
    int numPageReads = 0;
    int numPageWrites = 0;

    // Calculate the number of disk transfers (page reads and writes) for column major order
    for (int J = 1; J <= ARRAY_SIZE; J++) {
        for (int I = 1; I <= ARRAY_SIZE; I++) {
            int pageIndex = (J - 1) / PAGE_SIZE;

            if (pageIndex >= ACTIVE_MEMORY_SET_SIZE) {
                numPageReads++;
            }
            numReads++;

            numWrites++;
            if (pageIndex >= ACTIVE_MEMORY_SET_SIZE) {
                numPageWrites++;
            }
        }
    }

    int numDiskReads = numPageReads / PAGE_SIZE;
    int numDiskWrites = numPageWrites / PAGE_SIZE;

    std::cout << "Column Major Order:\n";
    std::cout << "Number of Disk Reads: " << numDiskReads << "\n";
    std::cout << "Number of Disk Writes: " << numDiskWrites << "\n";
}

int main() {
    rowMajorOrder();
    std::cout << "------------------------\n";
    columnMajorOrder();

    return 0;
}
