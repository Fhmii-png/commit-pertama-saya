#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Mahasiswa {
private:
    string stambuk;
    string nama;
    int angkatan;
    string kelas;

public:
    // Constructor
    Mahasiswa(string stambuk, string nama, int angkatan, string kelas) {
        this->stambuk = stambuk;
        this->nama = nama;
        this->angkatan = angkatan;
        this->kelas = kelas;
    }

    // Getter
    string getStambuk() {
        return stambuk;
    }

    string getNama() {
        return nama;
    }

    int getAngkatan() {
        return angkatan;
    }

    string getKelas() {
        return kelas;
    }

    // Tampilkan data mahasiswa
    void tampilData() {
        cout << "Stambuk   : " << stambuk << endl;
        cout << "Nama      : " << nama << endl;
        cout << "Angkatan  : " << angkatan << endl;
        cout << "Kelas     : " << kelas << endl;
        cout << "===============================" << endl;
    }
};

int main() {
    vector<Mahasiswa> daftarMahasiswa;
    int pilihan;

    do {
        cout << "Menu:\n";
        cout << "1. Input Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "Masukkan Pilihan [1..5] : ";
        cin >> pilihan;
        cin.ignore(); // Bersihkan newline setelah input angka

        if (pilihan == 1) {
            string stambuk, nama, kelas;
            int angkatan;

            cout << "Masukkan stambuk  : ";
            getline(cin, stambuk);
            cout << "Masukkan nama     : ";
            getline(cin, nama);
            cout << "Masukkan angkatan : ";
            cin >> angkatan;
            cin.ignore();
            cout << "Masukkan kelas    : ";
            getline(cin, kelas);

            daftarMahasiswa.push_back(Mahasiswa(stambuk, nama, angkatan, kelas));
            cout << "Data berhasil ditambahkan.\n";

        } else if (pilihan == 2) {
            if (daftarMahasiswa.empty()) {
                cout << "Belum ada data mahasiswa.\n";
            } else {
                for (int i = 0; i < daftarMahasiswa.size(); i++) {
                    daftarMahasiswa[i].tampilData();
                }
            }

        } else if (pilihan == 3) {
            string cariStambuk;
            bool ditemukan = false;

            cout << "Masukkan stambuk yang dicari : ";
            getline(cin, cariStambuk);

            for (int i = 0; i < daftarMahasiswa.size(); i++) {
                if (daftarMahasiswa[i].getStambuk() == cariStambuk) {
                    cout << "Data ditemukan:\n";
                    daftarMahasiswa[i].tampilData();
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Data tidak ditemukan.\n";
            }

        } else if (pilihan == 4) {
            string hapusStambuk;
            bool terhapus = false;

            cout << "Masukkan stambuk yang ingin dihapus : ";
            getline(cin, hapusStambuk);

            for (int i = 0; i < daftarMahasiswa.size(); i++) {
                if (daftarMahasiswa[i].getStambuk() == hapusStambuk) {
                    daftarMahasiswa.erase(daftarMahasiswa.begin() + i);
                    cout << "Data berhasil dihapus.\n";
                    terhapus = true;
                    break;
                }
            }

            if (!terhapus) {
                cout << "Data tidak ditemukan.\n";
            }

        } else if (pilihan == 5) {
            cout << "Terima kasih. Program selesai.\n";

        } else {
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }

        cout << endl;

    } while (pilihan != 5);

    return 0;
}

