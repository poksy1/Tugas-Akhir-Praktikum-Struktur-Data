#include <iostream> 
using namespace std;

const int SIZE = 10;

struct Mahasiswa {
    string nama;
    double ipk;
};
struct DataMahasiswa {
    int nim;          
    Mahasiswa data;   
    DataMahasiswa* next;
};
void initSistem(DataMahasiswa* sistem[]) {
    for (int i = 0; i < SIZE; i++) {
        sistem[i] = nullptr;
    }
}
int hashFunction(int nim) {
    return (nim % SIZE + SIZE) % SIZE;
}
void tambahMahasiswa(DataMahasiswa* sistem[], int nim, Mahasiswa data) {
    int index = hashFunction(nim);
     DataMahasiswa* cur = sistem[index];
    while (cur != nullptr) {
        if (cur->nim == nim) {
            cur->data = data;
            cout << "(Info: Data NIM " << nim << " berhasil di-update.)\n";
            return;
        }
        cur = cur->next;
    }
    DataMahasiswa* baru = new DataMahasiswa;
    baru->nim = nim;
    baru->data = data;
    baru->next = sistem[index]; // Sisipkan di depan
    sistem[index] = baru; // Update kepala antrean
}
DataMahasiswa* cariMahasiswa(DataMahasiswa* sistem[], int nim) {
    int index = hashFunction(nim);

    DataMahasiswa* cur = sistem[index];
    while (cur != nullptr) {
        if (cur->nim == nim) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}
void hapusMahasiswa(DataMahasiswa* sistem[], int nim) {
    int index = hashFunction(nim);
    DataMahasiswa* cur = sistem[index];
    DataMahasiswa* prev = nullptr;

    while (cur != nullptr) {
        if (cur->nim == nim) {
            if (prev == nullptr) {
                sistem[index] = cur->next;
            } else {
                prev->next = cur->next;
            }
            delete cur; // Hapus data dari memori
            cout << "\n(Info: Data NIM " << nim << " berhasil dihapus.)\n";
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "\n(Info: Data NIM " << nim << " tidak ditemukan, penghapusan gagal.)\n";
}
void tampilkanSistem(DataMahasiswa* sistem[]) {
    cout << "\n===== Sistem Data Mahasiswa =====\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Loket " << i << ": ";
        DataMahasiswa* tmp = sistem[i];
        if (tmp == nullptr) {
            cout << "KOSONG";
        }
        while (tmp != nullptr) {
            cout << "[NIM: " << tmp->nim 
                 << ", Nama: " << tmp->data.nama 
                 << ", IPK: " << tmp->data.ipk << "] -> ";
            tmp = tmp->next;
        }
        if (tmp == nullptr && sistem[i] != nullptr) {
            cout << "AKHIR ANTRIAN";
        }
        cout << "\n";
    }
    cout << "=================================\n";
}

int main() {
    DataMahasiswa* sistemRegistrasi[SIZE];
    initSistem(sistemRegistrasi);
    tambahMahasiswa(sistemRegistrasi, 130121, {"Budi", 3.5});   // Loket 1
    tambahMahasiswa(sistemRegistrasi, 130131, {"Ani", 3.8});    // Loket 1 (Kolisi)
    tambahMahasiswa(sistemRegistrasi, 130141, {"Dono", 3.2});   // Loket 1 (Kolisi)
    tambahMahasiswa(sistemRegistrasi, 140112, {"Citra", 3.9});  // Loket 2
    tampilkanSistem(sistemRegistrasi);
    cout << "\n===== Proses Pencarian =====\n";
    DataMahasiswa* hasilCari = cariMahasiswa(sistemRegistrasi, 130131);   
    if (hasilCari != nullptr) {
        cout << "Data NIM " << hasilCari->nim << " ditemukan:\n";
        cout << "Nama: " << hasilCari->data.nama 
             << ", IPK: " << hasilCari->data.ipk << endl;
    } else {
        cout << "Data NIM 130131 tidak ditemukan.\n";
    }
    cout << "============================\n";
    hapusMahasiswa(sistemRegistrasi, 130131);
    tampilkanSistem(sistemRegistrasi);
    hapusMahasiswa(sistemRegistrasi, 999999);
    return 0;
}