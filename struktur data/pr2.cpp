#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;


void buatNodeAwal(int nilai) {
    if (head != NULL) {
        cout << "Node awal sudah ada!" << endl;
        return;
    }
    head = new Node;
    head->data = nilai;
    head->next = NULL;
    cout << "Nilai " << nilai << " berhasil dimasukkan di node awal." << endl;
}


void tambahNode(int nilai) {
    if (head == NULL) {
        cout << "Linked list masih kosong, buat node awal dulu!" << endl;
        return;
    }

    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = baru;
    cout << "Node dengan nilai " << nilai << " berhasil ditambahkan." << endl;
}


void hapusNode(int nilai) {
    if (head == NULL) {
        cout << "Linked list kosong!" << endl;
        return;
    }

    Node *cur = head;
    Node *prev = NULL;

    while (cur != NULL && cur->data != nilai) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Node dengan nilai " << nilai << " tidak ditemukan." << endl;
        return;
    }

    if (prev == NULL) {
        head = head->next; 
    } else {
        prev->next = cur->next;
    }

    delete cur;
    cout << "Node dengan nilai " << nilai << " berhasil dihapus." << endl;
}


void tampilData() {
    if (head == NULL) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Node *cur = head;
    cout << "Isi Linked List:" << endl;
    cout << "================" << endl;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}


int main() {
    int pilihan, nilai;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Buat Node Awal" << endl;
        cout << "2. Tambah Node" << endl;
        cout << "3. Hapus Node" << endl;
        cout << "4. Tampil Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan [1..5]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nBuat Node Baru" << endl;
                cout << "===============" << endl;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                buatNodeAwal(nilai);
                break;

            case 2:
                cout << "\nTambah Node Baru" << endl;
                cout << "================" << endl;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahNode(nilai);
                break;

            case 3:
                cout << "\nHapus Node" << endl;
                cout << "============" << endl;
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusNode(nilai);
                break;

            case 4:
                cout << endl;
                tampilData();
                break;

            case 5:
                cout << "Keluar dari program..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}

