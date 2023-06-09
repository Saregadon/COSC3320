#include <iostream>
#include <unordered_map>
#include <list>

const int PAGE_SIZE = 2000;
const int ACTIVE_MEMORY_SET_SIZE = 1000;
const int ARRAY_SIZE = 4000;

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, std::list<int>::iterator> cache;
    std::list<int> pageList;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    void refer(int pageIndex) {
        if (cache.find(pageIndex) == cache.end()) {
            if (pageList.size() == capacity) {
                int lastPage = pageList.back();
                pageList.pop_back();
                cache.erase(lastPage);
            }
        } else {
            pageList.erase(cache[pageIndex]);
        }

        pageList.push_front(pageIndex);
        cache[pageIndex] = pageList.begin();
    }

    int getNumPageFaults() {
        return pageList.size() - ACTIVE_MEMORY_SET_SIZE;
    }

    int getNumDiskReads() {
        return (getNumPageFaults() + PAGE_SIZE - 1) / PAGE_SIZE;
    }

    int getNumDiskWrites() {
        return (pageList.size() + PAGE_SIZE - 1) / PAGE_SIZE;
    }
};

void simulateLRU() {
    int numPageReads = 0;
    int numPageWrites = 0;

    LRUCache cache(ACTIVE_MEMORY_SET_SIZE);

    for (int I = 1; I <= ARRAY_SIZE; I++) {
        for (int J = 1; J <= ARRAY_SIZE; J++) {
            int pageIndex = (I - 1) / PAGE_SIZE;

            if (pageIndex >= ACTIVE_MEMORY_SET_SIZE) {
                numPageReads++;
            }

            cache.refer(pageIndex);

            numPageWrites++;
        }
    }

    int numDiskReads = cache.getNumDiskReads();
    int numDiskWrites = cache.getNumDiskWrites();

    std::cout << "Number of Disk Reads: " << numDiskReads << "\n";
    std::cout << "Number of Disk Writes: " << numDiskWrites << "\n";
}

int main() {
    std::cout << "Row Major Order:\n";
    simulateLRU();
    std::cout << "------------------------\n";
    std::cout << "Column Major Order:\n";
    simulateLRU();

    return 0;
}
