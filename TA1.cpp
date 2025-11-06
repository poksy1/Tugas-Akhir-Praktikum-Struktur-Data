#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah angka: ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++) {
        cout << "Masukkan angka ke-" << (i + 1) << ": ";
        cin >> angka[i];
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (angka[j] > angka[j+1]) {
                int temp = angka[j];
                angka[j] = angka[j+1];
                angka[j+1] = temp;
            }
        }
    }
    cout << "\nAngka yang sudah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << endl;
    return 0;
}
