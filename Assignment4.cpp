#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int n = 0;

    vector<vector<int>> A(65536, vector<int>(65536));
    vector<vector<int>> B(65536, vector<int>(65536));
    vector<vector<int>> C(65536, vector<int>(65536));
    vector<vector<int>> D(65536, vector<int>(65536));
    vector<vector<int>> E(65536, vector<int>(65536));
    vector<vector<int>> F(65536, vector<int>(65536));

    for(n = 128; n <= 65536; n *= 2){
        auto start = high_resolution_clock::now(); // Timer start
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                C[i][j] = A[i][j] + B[i][j];
            }
        }
        auto stop = high_resolution_clock::now(); // Timer stop
        auto duration = duration_cast<nanoseconds>(stop - start);  // Calculate the duration

        cout << "Time taken for n = " << n << ": " << duration.count() << " nanoseconds" << endl;
    }

    for(n = 128; n <= 65536; n *= 2){
        auto start2 = high_resolution_clock::now(); // Timer start
        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                C[i][j] = A[i][j] + B[i][j];
            }
        }
        auto stop2 = high_resolution_clock::now(); // Timer stop
        auto duration2 = duration_cast<nanoseconds>(stop2 - start2);  // Calculate the duration

        cout << "Time taken for n = " << n << ": " << duration2.count() << " nanoseconds" << endl;
    }

    return 0;
}
