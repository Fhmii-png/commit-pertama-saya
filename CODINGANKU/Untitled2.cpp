#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Mahasiswa {
private:
    string stambuk;
    string nama;
    string kelas;
    int angkatan;

public:
    Mahasiswa() {
        stambuk = "";
        nama = "";
        kelas = "";
        angkatan = 0;
    }

    Mahasiswa(string s, string n, int a, string k) {
        stambuk = s;
        nama = n;
        angkatan = a;
        kelas = k;
    }

    void setData(string s, string n, int a, string k) {
        stambuk = s;
        nama = n;
        angkatan = a;
        kelas = k;
    }

    void tampil() {
        cout << "Stambuk  : " << stambuk << endl;
        cout << "Nama     : " << nama << endl;
        cout << "Kelas    : " << kelas << endl;
        cout << "Angkatan : " << angkatan << endl;
    }

    string getStambuk() {
        return stambuk;
    }
};

vector<Mahasiswa> daftarMahasiswa;

void inputData(int metode) {
    string stambuk, nama, kelas;
    int angkatan;

    cout << "\nMasukkan stambuk  : ";
    cin >> stambuk;
    cin.ignore();
    cout << "Masukkan nama     : ";
    getline(cin, nama);
    cout << "Masukkan angkatan : ";
    cin >> angkatan;
    cout << "Masukkan kelas    : ";
    cin >> kelas;

    Mahasiswa mhs;
    if (metode == 1) {
        mhs = Mahasiswa(stambuk, nama, angkatan, kelas);
    } else {
        mhs.setData(stambuk, nama, angkatan, kelas);
    }

    daftarMahasiswa.push_back(mhs);
    cout << "\nData berhasil ditambahkan!\n";
}

void tampilData() {
    if (daftarMahasiswa.empty()) {
        cout << "\nBelum ada data mahasiswa.\n";
        return;
    }

    cout << "\nDaftar Mahasiswa:\n";
    for (int i = 0; i < daftarMahasiswa.size(); i++) {
        cout << "\nMahasiswa ke-" << i + 1 << ":\n";
        daftarMahasiswa[i].tampil();
    }
}

void cariData() {
    string cariStambuk;
    cout << "Masukkan stambuk yang dicari: ";
    cin >> cariStambuk;
    bool ditemukan = false;

    for (int i = 0; i < daftarMahasiswa.size(); i++) {
        if (daftarMahasiswa[i].getStambuk() == cariStambuk) {
            cout << "\nData ditemukan:\n";
            daftarMahasiswa[i].tampil();
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan.\n";
    }
}

void hapusData() {
    string hapusStambuk;
    cout << "Masukkan stambuk yang ingin dihapus: ";
    cin >> hapusStambuk;
    bool dihapus = false;

    for (int i = 0; i < daftarMahasiswa.size(); i++) {
        if (daftarMahasiswa[i].getStambuk() == hapusStambuk) {
            daftarMahasiswa.erase(daftarMahasiswa.begin() + i);
            cout << "Data berhasil dihapus.\n";
            dihapus = true;
            break;
        }
    }

    if (!dihapus) {
        cout << "Data tidak ditemukan.\n";
    }
}

int main() {
    int pilihan;
    int metodeInisialisasi;

    cout << "Pilih metode inisialisasi:\n";
    cout << "1. Konstruktor\n";
    cout << "2. Public function\n";
    cout << "Masukkan pilihan [1..2]: ";
    cin >> metodeInisialisasi;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "Masukkan Pilihan [1..5]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: inputData(metodeInisialisasi); break;
            case 2: tampilData(); break;
            case 3: cariData(); break;
            case 4: hapusData(); break;
            case 5: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n"; break;
        }
    } while (pilihan != 5);

    return 0;
}

