#include <iostream>
using namespace std;

struct Hewan {
    string jenis;
    string nama;
    int umur;
    float berat;
};

int main() {
    int jumlah;
    float totalBerat = 0;

    cout << "Masukkan jumlah hewan yang dititipkan: ";
    cin >> jumlah;

    Hewan* data = new Hewan[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "\nHewan ke-" << i+1 << ":\n";
        cout << "Jenis: ";
        cin.ignore();
        getline(cin, data[i].jenis);
        cout << "Nama: ";
        getline(cin, data[i].nama);
        cout << "Umur (tahun): ";
        cin >> data[i].umur;
        cout << "Berat (kg): ";
        cin >> data[i].berat;

        totalBerat += data[i].berat;
    }

    cout << "\n=== Daftar Hewan Dititipkan ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i+1 << ". " << data[i].jenis << " | Nama: " << data[i].nama
             << " | Umur: " << data[i].umur << " tahun | Berat: "
             << data[i].berat << " kg\n";
    }

    cout << "\nTotal berat semua hewan: " << totalBerat << " kg\n";
    return 0;
}

