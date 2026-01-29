#include <iostream>
#include <vector>
#include <chrono> 

using namespace std;
using namespace std::chrono; 

void solve(const vector<int>& D, int n, int k) {
    int min_len = n + 1;
    long long steps = 0; // Licznik operacji
 
  //start "zegarka"
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            steps++; // Zliczamy operację główną

            sum += D[j];
            if (sum > k) {
                int len = j - i + 1;
                if (len < min_len) {
                    min_len = len;
                    
                }
                break;
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); 

    cout << "N = " << n;
    cout<< " | Operacje: " << steps; 
    cout << " | Czas: " << double(duration.count())/1000000 << " ms" << endl;
}

int main() {
    int rozmiary[] = {10, 100, 500, 1000, 2000, 5000, 10000};
    int k = INT32_MAX; 

    cout << "--- TEST WYDAJNOSCI ---" << endl;
    
    for (int n : rozmiary) {
        vector<int> D(n);
        for(int i=0; i<n; i++) D[i] = rand() % 100;

        solve(D, n, k);
    }

    return 0;
}