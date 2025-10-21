#include<iostream>
using namespace std;

struct barang{
    string namaBarang;
    int expired;
    int jumlahBarang;
    int hargaBarang;

    barang *next;
};

barang *head, *tail, *cur, *newB;

void createBarang(string namaBarang, int expired, int jumlahbarang, int hargaBarang){
    head = new barang();
    head-> namaBarang = namaBarang;
    head-> expired = expired;
    head-> jumlahBarang = jumlahbarang;
    head-> hargaBarang = hargaBarang;
    head ->next = NULL;
    tail = head;
}
void Barang1(string namaBarang, int expired, int jumlahbarang, int hargaBarang){
    head = new barang();
    newB-> namaBarang = namaBarang;
    newB-> expired = expired;
    newB-> jumlahBarang = jumlahbarang;
    newB-> hargaBarang = hargaBarang;
    newB ->next = head;
    head= NULL;
}
void printbarang(){
    cur = head;
    while (cur != NULL){
        cout<<"Nama Barang: "<<cur->namaBarang<<endl;
        cout<<"Expired: "<<cur->expired<<endl;
        cout<<"Jumlah barang: "<<cur->jumlahBarang<<endl;
        cout<<"harga: "<<cur->hargaBarang;
        cur = cur->next;
    }
}
int main(){
    createBarang ("masako", 2025, 12, 2000);
    printbarang();

}



