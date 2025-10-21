#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

void push(int data) {
    if (top == MAX - 1) {
        cout << "Stack penuh!" << endl;
        return;
    }
   
 top++;
    stack[top] = data;
    cout << "Data " << data << " berhasil ditambahkan ke stack." << endl;
}

void pop() {
    if (top == -1) {
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Data " << stack[top] << " berhasil dihapus dari stack." << endl;
    top--;
}

void tampil() {
    if (top == -1) {
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Isi Stack: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

void kosongkan() {
    top = -1;
    cout << "Stack berhasil dikosongkan." << endl;
}

int main() {
    int pilihan, data;
    string nama;
    
    cout<<"Muh. Fahmi Ashar"<<endl;
    cout<<"13020240333"<<endl;

    do {
        cout << "\nImplementasi Stack dengan Array" << endl;
        cout << "===============================" << endl;
        cout << "1. Push Data" << endl;
        cout << "2. Pop Data" << endl;
        cout << "3. Tampil Isi Stack" << endl;
        cout << "4. Kosongkan Stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan [1..5]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                tampil();
                break;
            case 4:
                kosongkan();
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

