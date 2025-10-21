#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string judul;
    string pengarang;
    int tahun;

    // Constructor
    Book(string j, string p, int t) {
        judul = j;
        pengarang = p;
        tahun = t;
    }

    // Method untuk menampilkan informasi buku
    void tampilkan() {
        cout << "Judul     : " << judul << endl;
        cout << "Pengarang : " << pengarang << endl;
        cout << "Tahun     : " << tahun << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    int jumlah;
    cout << "Masukkan jumlah buku yang ingin dicatat: ";
    cin >> jumlah;

    vector<Book> daftarBuku;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nBuku ke-" << (i + 1) << endl;
        string judul, pengarang;
        int tahun;

        cin.ignore(); // membersihkan newline
        cout << "Masukkan judul: ";
        getline(cin, judul);
        cout << "Masukkan pengarang: ";
        getline(cin, pengarang);
        cout << "Masukkan tahun terbit: ";
        cin >> tahun;

        Book b(judul, pengarang, tahun);
        daftarBuku.push_back(b);
    }

    cout << "\n=== Daftar Buku ===\n";
    for (int i = 0; i < daftarBuku.size(); i++) {
        daftarBuku[i].tampilkan();
    }

    return 0;
}

