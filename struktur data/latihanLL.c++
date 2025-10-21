#include<iostream>
using namespace std;

struct LL{
    int tb;

    LL *next;
};

LL *head = NULL, *tail, *cur;

void LinkedList(int tb ){
    LL *baru = new LL();
    baru->tb = tb;
    baru->next=NULL;

    if (head == NULL){
        head  = baru;
        tail = baru;
    }else{
        tail->next = baru;
    }
    tail =baru;
}
void tampilkan(){
    cur=head;
    while(cur != NULL){
        cout<<"Linked List: "<<cur->tb<<endl;;
       cout<<endl;
        cur = cur->next;
    }

}
int main (){
    LinkedList (10);
    LinkedList (11);
    LinkedList (12);
    tampilkan();

}

