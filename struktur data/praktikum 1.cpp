#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL; // penunjuk ke awal linked list

// Fungsi untuk menambahkan data ke linked list
void tambahData(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Fungsi untuk menampilkan seluruh data
void tampilkan() {
    Node *temp = head;
    cout << "Data dalam Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Menambahkan tiga data
    tambahData(10);
    tambahData(20);
    tambahData(30);

    // Menampilkan semua data
    tampilkan();

    return 0;
}

