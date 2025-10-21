#include <iostream>
using namespace std;

class Mobil {
    string merk;
    int tahun_pembuatan;
    double harga;

public:
    Mobil(string m, int t, double h) {
        merk = m;
        tahun_pembuatan = t;
        harga = h;
    }
    void setMerk(string m) {
        merk = m;
    }
    void setTahun(int t) {
        tahun_pembuatan = t;
    }
    void setHarga(double h) {
        harga = h;
    }
    string getMerk() {
        return merk;
    }
    int getTahun() {
        return tahun_pembuatan;
    }
    double getHarga() {
        return harga;
    }
    void tampilkanInfo() {
        cout << "Mobil " << merk << ", tahun pembuatan " << tahun_pembuatan
             << ", harga Rp" << harga << endl;
    }
};
int main() {
    cout << "Informasi mobil:" << endl;

    Mobil m1("Toyota", 2020, 2e8);
    Mobil m2("Honda", 2019, 1.8e8);
    Mobil m3("Mazda", 2022, 3e8);

    m1.tampilkanInfo();
    m2.tampilkanInfo();
    m3.tampilkanInfo();

    return 0;
}

