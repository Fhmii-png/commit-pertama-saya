#include <iostream>
#include <iomanip>  
using namespace std;

struct Lingkaran {
    double jari; 
    double luas() {
        return 3.14 * jari * jari;
    }
    double keliling() {
        return 2 * 3.14 * jari;
    }
};

int main() {
    Lingkaran lingkaran;  
    char ulang;          
    do {
        cout << "Masukkan nilai jari-jari lingkaran: ";
        cin >> lingkaran.jari;

        cout << fixed << setprecision(2);

        cout << "Luas lingkaran: " << lingkaran.luas() << endl;
        cout << "Keliling lingkaran: " << lingkaran.keliling();

        cout << "\n\nApakah Anda ingin mengulang program? (Y/N): ";
        cin >> ulang;
        cout << endl;

    } while (ulang == 'Y' || ulang == 'y');  
    return 0;
}

