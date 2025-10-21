#include <iostream>
using namespace std;


int f(int n) {
    if (n == 0) {
        return 3; 
    } else {
        return 2 * f(n - 1) + 4;
    }
}

int main() {
    int n;

    cout << "Masukkan nilai n: ";
    cin >> n;

    int hasil = f(n);
    cout << "Hasil f(" << n << ") adalah: " << hasil << endl;

    return 0;
}

