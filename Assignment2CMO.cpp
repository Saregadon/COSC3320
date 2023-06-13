#include <iostream>
#include <unordered_map>
#include <list>

const int PAGE_SIZE = 2000; //page size in words
const int ACTIVE_MEMORY_SIZE = 1000; //max number of pages based on LRU

int calculatePageNumber(int i, int j) { //calculates page transfer counts
    return (i * j) * 10;
}

std::pair<int, int> calculatePageTransfersColumnMajor() {
    int totalReads = 0;
    int totalWrites = 0;
    std::unordered_map<int, bool> pageTable;
    std::list<int> activePages;

    for (int j = 1; j <= 4000; ++j) { // Columns
        for (int i = 1; i <= 4000; ++i) { // Rows
            // Access A[i, j]
            int page = calculatePageNumber(i, j);
            if (pageTable.find(page) == pageTable.end()) {
                if (activePages.size() < ACTIVE_MEMORY_SIZE) {
                    activePages.push_back(page);
                } else {
                    int evictedPage = activePages.front();
                    activePages.pop_front();
                    activePages.push_back(page);
                    pageTable.erase(evictedPage);
                    ++totalWrites;
                }
                pageTable[page] = true;
                ++totalReads;
            }

            // Access B[i, j]
            page = calculatePageNumber(j, i);
            if (pageTable.find(page) == pageTable.end()) {
                if (activePages.size() < ACTIVE_MEMORY_SIZE) {
                    activePages.push_back(page);
                } else {
                    int evictedPage = activePages.front();
                    activePages.pop_front();
                    activePages.push_back(page);
                    pageTable.erase(evictedPage);
                    ++totalWrites;
                }
                pageTable[page] = true;
                ++totalReads;
            }
        }
    }

    return std::make_pair(totalReads, totalWrites);
}



int main() {
    std::pair<int, int> pageTransfers = calculatePageTransfersColumnMajor();
    int totalReads = pageTransfers.first;
    int totalWrites = pageTransfers.second;

    std::cout << "Total reads: " << totalReads << std::endl;
    std::cout << "Total writes: " << totalWrites << std::endl;

    return 0;
}
//g++ Assignment2.cpp -o Assignment && ./Assignment to build and run

/*
The code uses an unordered map pageTable to track the pages currently in main memory. It maps page numbers to boolean 
values to indicate whether a page is present in memory.
A list activePages is used to simulate the LRU replacement strategy. It keeps track of the most recently used pages, 
with the least recently used page being at the front of the list.
In this column-major order version, the outer loop iterates over the columns (j), and the inner loop iterates over the 
rows (i). This ensures that elements from the same column are accessed consecutively.

Time Complexity -
The time complexity is O(N^2) where n is the max cases which is i = 4000 and j = 4000. So it is O(n^2) where n = 4000.
Since we're using the hash table, the active memory size is the n when measure the O(n), so the case for Space complexity
is O(1). 
Space Complexity - 
pageTable: An unordered map that can hold a maximum of 1000 pages in memory. As the maximum active memory size is defined 
as 1000, the space complexity of the pageTable is O(ACTIVE_MEMORY_SIZE), which is O(1) in this case.
activePages: A list that simulates the LRU replacement strategy. It can hold a maximum of 1000 page numbers. Thus, the 
space complexity of the activePages list is O(ACTIVE_MEMORY_SIZE), which is O(1) as well.
*/