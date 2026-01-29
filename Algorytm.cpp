#include <iostream>
using namespace std;

void solve(int D[], int n, int k) {
    int min_len = n + 1; 
    int k_i = -1;
    int k_j = -1;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += D[j];

            if (sum > k) {
                int len = j - i + 1;
                
                if (len < min_len) {
                    min_len = len;
                    k_i = i;
                    k_j = j;
                }
                break; 
            } 
        }}
    cout << "Wejście: ";
    for (int i = 0; i < n; i++) {
        cout << D[i] << " ";
    }
    cout << " | k = " << k << endl;

    if (k_i == -1) {
        cout << "Wyjście: Brak Podtablic spełniających warunek" << endl;
    } else {
        cout << "Wyjście: ";
        for (int i = k_i; i <= k_j; i++) {
            cout << D[i] << " ";
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
    
}
int main() {
    int D[] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    int n = sizeof(D) / 4; 

    solve(D, n, 20);
    solve(D, n, 21);
    solve(D, n, 7);
    solve(D, n, 40);
    return 0;
}
