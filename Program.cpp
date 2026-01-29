#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void solve(int D[], int n, int k,ofstream& outFile) {
    int min_len = n + 1; //inicjalizacja minimalnej długości podtablicy spełniajacej warunek
    int k_i = -1;   //indeksy początkowy
    int k_j = -1;   //indeks końcowy
    //szukanie podtablicy
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
        //wyswietlanie wyników na konsoli
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
    //zapisywanie wyników do pliku
    if (k_i == -1) {
        outFile << "-1" << endl;
    } else {
        for (int i = k_i; i <= k_j; i++) outFile << D[i] << " ";
        outFile << endl;
    }
    
}
int main() {
    //Wczytywanie danych z pliku data.txt
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Nie można otworzyć pliku data.txt" << endl;
        return 1;
    }
    //Tworzenie pliku wyniki.txt do zapisu wyników
    ofstream outputFile("wyniki.txt");
    if (!outputFile.is_open()) {
        cout << "Nie można utworzyć pliku wyniki.txt" << endl;
        return 1;
    }
    //Wczytywanie danych do wektora
    vector<int> D;
    int tempValue;
    while (file >> tempValue) {
        D.push_back(tempValue);
    }
    //Określenie rozmiaru tablicy
    int n = D.size();
   //Sprawdzanie funkcji solve
    solve(D.data(), n, 20, outputFile);
    solve(D.data(), n, 21, outputFile);
    solve(D.data(), n, 7, outputFile);
    solve(D.data(), n, 40, outputFile);
    //Zamknięcie plików
    file.close();
    outputFile.close(); 
    return 0;
}
