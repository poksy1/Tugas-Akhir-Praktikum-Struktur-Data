#include <iostream>
using namespace std;

int main() {
    const int x = 9; 
    string data[x] = {"Ali", "Budi", "Eka", "Ali", "Eka", "Fahmi", "Gita", "Hadi", "Gita"};
    string target;
    int i = 0;
    int counter = 0;

    cout << "Masukkan nama yang ingin dicari: ";
    cin >> target;

    while (i < x) {
        if (data[i] == target) {
            counter++;
        }
        i++;
    }

    if (counter > 0) {
        cout << "Nama " << target << " ditemukan sebanyak " << counter << " kali." << endl;
    } else {
        cout << "Nama " << target << " tidak ditemukan." << endl;
    }

    return 0;
}
