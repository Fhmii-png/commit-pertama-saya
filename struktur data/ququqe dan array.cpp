#include <iostream>
using namespace std;

#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        cout << "Queue penuh!" << endl;
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = data;
    cout << "Data " << data << " berhasil dimasukkan ke queue." << endl;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue kosong!" << endl;
        return;
    }
    cout << "Data " << queue[front] << " berhasil dihapus dari queue." << endl;
    front++;
    if (front > rear) front = rear = -1; // reset
}

void tampil() {
    if (front == -1) {
        cout << "Queue kosong!" << endl;
        return;
    }
    cout << "Isi Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

void kosongkan() {
    front = rear = -1;
    cout << "Queue berhasil dikosongkan." << endl;
}

int main() {
    int pilihan, data;
    

    do {
        cout << "\nImplementasi Queue dengan Array" << endl;
        cout << "===============================" << endl;
        cout << "1. Enqueue Data" << endl;
        cout << "2. Dequeue Data" << endl;
        cout << "3. Tampil Isi Queue" << endl;
        cout << "4. Kosongkan Queue" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan [1..5]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                enqueue(data);
                break;
            case 2:
                dequeue();
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

