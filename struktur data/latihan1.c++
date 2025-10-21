#include<iostream>
using namespace std;

struct barang{
	string nama;
	int jumlah;
	int harga;
	
	barang *next;
};


barang *head=NULL, *tail, *cur;

void barang1 (string nama, int jumlah, int harga){
	barang *baru = new barang();
	baru->nama = nama;
	baru->jumlah = jumlah;
	baru->harga = harga;
	baru ->next = NULL;
	
	if (head == NULL){
		head =baru;
		tail = baru;
	}else{
		tail->next = baru;
		}
		tail = baru;
}


void tampilkan(){
	cur=head;
	while (cur != NULL){
		cout<<"Nama Barang:"<<cur->nama<<endl;
		cout<<"Jumlah Barang: "<<cur->jumlah<<endl;
		cout<<"Harga Barang: "<<cur->harga<<endl;
		cout<<endl;
		cur = cur->next;
		
	}
}
	
int main (){
	barang1 ("Masako", 2, 2000);
	barang1 ("Mie GOreng", 4, 10000);
	barang1 ("Mie 1 dos", 2, 110000);
	tampilkan();		
	cout<<endl;
	

}
	
	
