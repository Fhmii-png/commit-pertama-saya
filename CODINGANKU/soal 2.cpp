#include <iostream>
#include <iomanip>
using namespace std;

class Lingkaran {
private:
    float jariJari;
    const float phi = 3.14; 
    
public:
    
    Lingkaran(float r) {
        jariJari = r;
    }
    float hitungLuas() {
        return phi * jariJari * jariJari;
    }
    float hitungKeliling() {
        return 2 * phi * jariJari;
    }
};

int main() {
    char ulang;

    do {
        float r;
        cout << "Masukkan nilai jari-jari lingkaran: ";
        cin >> r;

        Lingkaran lingkaran(r);

        cout << fixed << setprecision(2);
        cout << "Luas lingkaran: " << lingkaran.hitungLuas() << endl;
        cout << "Keliling lingkaran: " << lingkaran.hitungKeliling() << endl;

        cout << "\nApakah Anda ingin mengulang program? (Y/N): ";
        cin >> ulang;
        cout << endl;

    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}

