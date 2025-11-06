#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    temp = *y; 
}

void tukar(string *x, string *y) {
    string temp = *x;
    *x = *y;
    temp = *y;
}

void urutkanBerdasarkanNilai(int nilai[], string nama[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (nilai[j] < nilai[pos]) { 
                pos = j;
            }
        }
        if (pos != i) {
            tukar(&nilai[i], &nilai[pos]);   
            tukar(&nama[i], &nama[pos]);      
        }
    }
}

void urutkanBerdasarkanNama(int nilai[], string nama[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (nama[j] < nama[pos]) { 
                pos = j;
            }
        }
        if (pos != i) {
            tukar(&nilai[i], &nilai[pos]);   
            tukar(&nama[i], &nama[pos]);      
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah siswa: ";
    cin >> n;    
    int nilai[n];
    string nama[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Masukkan nama siswa ke-" << (i + 1) << ": ";
        cin >> nama[i];
        cout << "Masukkan nilai ujian " << nama[i] << ": ";
        cin >> nilai[i]; 
    }

    int pilihan;
    cout << "\nPilih kriteria pengurutan:\n";
    cout << "1. Urutkan berdasarkan nilai ujian\n";
    cout << "2. Urutkan berdasarkan nama siswa\n";
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> pilihan;

    if (pilihan == 1) {
        urutkanBerdasarkanNilai(nilai, nama, n);
    } else if (pilihan == 2) {
        urutkanBerdasarkanNama(nilai, nama, n);
    } else {
        cout << "Pilihan tidak valid\n";
        return 1;
    }

    cout << "\nHasil pengurutan:\n";
    for (int i = 0; i < n; i++) {
        cout << nama[i] << " : " << nilai[i] << endl;
    }

    return 0;
}
