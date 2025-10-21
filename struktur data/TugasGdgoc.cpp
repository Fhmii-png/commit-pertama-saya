#include <iostream>
using namespace std;

int main() {
   
    int n; 
    int angka; 

    cout << "Masukkan jumlah angka yang ingin diperiksa: ";
    cin >> n;

    
    for (int i = 1; i <= n; i++) {
        cout << "Masukkan angka ke-" << i << ": ";
        cin >> angka;

        1
        if (angka % 2 == 0) {
            cout << angka << " adalah bilangan genap." << endl;
        } else {
            cout << angka << " adalah bilangan ganjil." << endl;
        }
    }

    cout << "\nProgram selesai. Terima kasih!" << endl;

    return 0;
}

