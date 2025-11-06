#include <iostream> 
using namespace std; 
 
int main() { 
    const int x = 11; 
    int data[x-1] = {3, 8, 1, 9, 0, 6, 7, 5, 12, 2}; 
    int target; 
    int i = 0; 
    int flag = 0; 
    cout << "Masukkan angka yang ingin dicari : "; 
    cin >> target; 
 
    data[x-1] = target; 
 
    while (data[i] != target) { 
        i++; 
    } 
 
    if (i < x-1) { 
        flag = 1; 
    } 
 
    if (flag == 1) { 
        cout << "Ditemukan pada indeks ke-" << i << endl; 
    } else { 
        cout << "Tidak ditemukan" << endl; 
    } 
 
    return 0; 
}