#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};


Node *head = NULL;


void tambahData(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}


void tampilkan() {
    Node *bantu = head;
    cout << "Isi linked list: ";
    while (bantu != NULL) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}


int main() {
   
    tambahData(10);
    tambahData(20);
    tambahData(30);

    // Tampilkan seluruh data
    tampilkan();

    return 0;
}
