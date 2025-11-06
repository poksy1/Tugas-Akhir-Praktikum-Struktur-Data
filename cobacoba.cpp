#include <iostream>
using namespace std;

void tukar(int*x, int*y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void tukar(string*x, string*y){
    string temp = *x;
    *x = *y;
    *y = temp;
}

void urutkannilai(int nilai[], string nama[], int n){
    for (int i = 0; i < n - 1; i++){
        int pos = i;
        for(int j = 1 + 1; j < n; j++){
            if(nilai[j] < nilai[pos]){
                pos = j;
            }
        }
    }
}
 