#include <iostream>
#include <vector>
using namespace std;

class Barang {
public:
    string nama;
    double harga;
    int stok;
    Barang(string n, double h, int s) : nama(n), harga(h), stok(s) {}
};

void tampilkanMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah barang\n";
    cout << "2. Hapus barang\n";
    cout << "3. Beli barang\n";
    cout << "4. Tampilkan daftar barang\n";
    cout << "5. Selesai\n";
    cout << "Pilih: ";
}

void tampilkanBarang(const vector<Barang>& daftar) {
    if (daftar.empty()) {
        cout << "Tidak ada barang dalam daftar.\n";
    } else {
        for (size_t i = 0; i < daftar.size(); i++) {
            cout << i + 1 << ". " << daftar[i].nama
                 << " | Harga: " << daftar[i].harga
                 << " | Stok: " << daftar[i].stok << endl;
        }
    }
}

int main() {
    vector <Barang> daftarBarang;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(); 

        if (pilihan == 1) {
            string nama;
            double harga;
            int stok;

            cout << "Nama barang: ";
            getline(cin, nama);
            cout << "Harga: ";
            cin >> harga;
            cout << "Stok: ";
            cin >> stok;

            daftarBarang.push_back(Barang(nama, harga, stok));
            cout << "Barang ditambahkan.\n";

        } else if (pilihan == 2) {
            tampilkanBarang(daftarBarang);
            int indeks;
            cout << "Masukkan nomor barang yang akan dihapus: ";
            cin >> indeks;
            if (indeks >= 1 && indeks <= daftarBarang.size()) {
                daftarBarang.erase(daftarBarang.begin() + indeks - 1);
                cout << "Barang dihapus.\n";
            } else {
                cout << "Indeks tidak valid.\n";
            }

        } else if (pilihan == 3) {
            tampilkanBarang(daftarBarang);
            int indeks, jumlah;
            cout << "Masukkan nomor barang yang ingin dibeli: ";
            cin >> indeks;
            cout << "Jumlah: ";
            cin >> jumlah;

            if (indeks >= 1 && indeks <= daftarBarang.size()) {
                if (daftarBarang[indeks - 1].stok >= jumlah) {
                    daftarBarang[indeks - 1].stok -= jumlah;
                    cout << "Pembelian berhasil.\n";
                } else {
                    cout << "Stok tidak cukup.\n";
                }
            } else {
                cout << "Indeks tidak valid.\n";
            }

        } else if (pilihan == 4) {
            tampilkanBarang(daftarBarang);

        } else if (pilihan == 5) {
            cout << "Program selesai.\n";

        } else {
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 5);

    return 0;
}

