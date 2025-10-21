#include <iostream>
using namespace std;

int main() {
    // 1. Variabel
    int n; // variabel untuk menyimpan jumlah angka
    int angka; // variabel untuk angka yang akan diperiksa

    cout << "Masukkan jumlah angka yang ingin diperiksa: ";
    cin >> n;

    // 2. Perulangan (looping)
    for (int i = 1; i <= n; i++) {
        cout << "Masukkan angka ke-" << i << ": ";
        cin >> angka;

        // 3. Percabangan (if-else)
        if (angka % 2 == 0) {
            cout << angka << " adalah bilangan genap." << endl;
        } else {
            cout << angka << " adalah bilangan ganjil." << endl;
        }
    }

    cout << "\nProgram selesai. Terima kasih!" << endl;

    return 0;
}
