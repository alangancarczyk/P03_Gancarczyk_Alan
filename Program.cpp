#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void solve(int D[], int n, int k,ofstream& outFile) {
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
    if (k_i == -1) {
        outFile << "-1" << endl;
    } else {
        for (int i = k_i; i <= k_j; i++) outFile << D[i] << " ";
        outFile << endl;
    }
    
}
int main() {
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Nie można otworzyć pliku data.txt" << endl;
        return 1;
    }
    ofstream outputFile("wyniki.txt");
    if (!outputFile.is_open()) {
        cout << "Nie można utworzyć pliku wyniki.txt" << endl;
        return 1;
    }
    vector<int> D;
    int tempValue;
    while (file >> tempValue) {
        D.push_back(tempValue);
    }

    int n = D.size();

    solve(D.data(), n, 20, outputFile);
    solve(D.data(), n, 21, outputFile);
    solve(D.data(), n, 7, outputFile);
    solve(D.data(), n, 40, outputFile);
    return 0;
}
