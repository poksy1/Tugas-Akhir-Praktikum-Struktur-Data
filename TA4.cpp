#include <iostream>
using namespace std;
const int MAX = 100;  
string stack[MAX];    
int topIdx = -1;      
bool isEmpty() {
    return topIdx == -1;
}
bool isFull() {
    return topIdx == MAX - 1;
}
void push(string name) {
    if (isFull()) {
        cout << "Antrian penuh, tidak bisa mendaftar\n";
        return;
    }
    stack[++topIdx] = name; 
    cout << "Siswa " << name << " berhasil didaftarkan\n";
}
void pop() {
    if (isEmpty()) {
        cout << "Tidak ada siswa yang bisa diproses\n";
        return;
    }
    cout << "Siswa " << stack[topIdx--] << " berhasil diproses\n"; 
}
void peek() {
    if (isEmpty()) {
        cout << "Tidak ada siswa yang terdaftar\n";
        return;
    }
    cout << "Siswa yang akan diproses berikutnya: " << stack[topIdx] << '\n';
}
void display() {
    if (isEmpty()) {
        cout << "Antrian kosong\n";
        return;
    }
    cout << "Daftar siswa yang menunggu pendaftaran (dari atas ke bawah):\n";
    for (int i = topIdx; i >= 0; --i) {
        cout << stack[i] << " ";
    }
    cout << endl;
}
int main() {
    int pilih;
    string name;
    do {
        cout << "\n=== Pendaftaran Siswa Baru ===\n";
        cout << "1. Daftarkan Siswa Baru\n";
        cout << "2. Proses Siswa\n";
        cout << "3. Lihat Siswa yang Akan Diproses\n";
        cout << "4. Tampilkan Daftar Siswa Menunggu\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        if (pilih == 1) {
            cout << "Masukkan Nama Siswa: ";
            cin.ignore(); 
            getline(cin, name);  
            push(name);  
        }
        else if (pilih == 2) {
            pop();  
        }
        else if (pilih == 3) {
            peek();  
        }
        else if (pilih == 4) {
            display();  
        }
    } while (pilih != 5); 
    return 0;
}
