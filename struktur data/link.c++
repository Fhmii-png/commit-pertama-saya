#include<iostream>
using namespace std;

struct buku{
    string judul, pengarang;
    int tahunTerbit;

    buku *next;
};
int main(){
    buku *node1, *node2, *node3;

    node1 = new buku();
    node2 = new buku();
    node3 = new buku();

    node1->judul = "Matematika";
    node1->pengarang = "fhmii";
    node1->tahunTerbit= 2019;
    node1->next=node2;

    node2->judul ="Bindo";
    node2->pengarang="agys";
    node2->tahunTerbit = 2011;
    node2->next= node3;

    node3->judul ="Alpro";
    node3->pengarang="ilham";
    node3->tahunTerbit = 2001;
    node3->next= NULL;


}