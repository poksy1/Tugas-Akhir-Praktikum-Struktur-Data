#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void tukar(string *x, string *y) {
    string temp = *x;
    *x = *y;
    *y = temp;
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
        cin >> nilai[i]; }
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++){
            if (nilai[j] < nilai[pos]) { 
                pos = j;
            }
        }
        if (pos != i) {
            tukar(&nilai[i], &nilai[pos]);   
            tukar(&nama[i], &nama[pos]);      
        }
    }
    cout << "\nNilai ujian siswa setelah diurutkan: \n";
    for (int i = 0; i < n; i++) {
        cout << nama[i] << " : " << nilai[i] << endl;
    }
    return 0;
}
