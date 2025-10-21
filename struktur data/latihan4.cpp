#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void tambahNode(Node*& head, int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilkan(Node* head) {
    Node* temp = head;
    cout << "Data dalam linked list: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    tambahNode( 10);
    tambahNode( 20);
    tambahNode( 30);

    tampilkan(head);

    return 0;
}
