#include<iostream>
using namespace std;

struct Node {
	int nilai ;
	
	Node *next;
};
Node *head =NULL;

void nodeAwal (int nilai){
	if (head != NULL){
		cout<<"node Awal sudah ada"<<endl;
		return;
	}
	head = new Node();
	head->nilai= nilai;
	head->next=NULL;
	cout<<"Nilai"<<nilai<<"Berhasil ditambahkan"<<endl;
	}

void tambahkanNode(int nilai){
	if(head == NULL){
		cout<<"Linked List Kosong, isi Node awal dulu"<<endl;
		return;
	}
	Node *baru = new Node();
	baru->nilai = nilai;
	baru->next= NULL;
	
	Node *cur = head;
	while (cur->next != NULL){
		cur = cur->next;
	}
	cur->next = baru;
	cout<<"Node dengan nilai "<<nilai<<" berhasil ditambahkan"<<endl;
}
void hapus(int nilai){
	if(head == NULL){
		cout<<"List kosong"<<endl;
		return;
	}
	Node *cur = head;
	Node *prev = NULL;
	
	while (cur != NULL && cur->nilai != nilai){
		prev = cur;
		cur=cur->next;
	}
	if (cur == NULL){
		cout<<"list masih kosong"<<nilai<<"tidak ditemukan"<<endl;
		return;
	}
	if (prev == NULL){
		head = head ->next;
	}
	else {
		prev->next = cur->next;
	}
	delete cur;
	cout<<"Node dengan nilai"<<nilai<<"berhasil dihapus"<<endl;
}
void tampilkan(){
	if (head == NULL){
		cout<<"list belum diisi"<<endl;
		return;
	}
	Node *cur = head;
	cout<<"Isi Linked List"<<endl;
	cout<<"================="<<endl;
	while (cur != NULL){
		cout<<cur->nilai<<" ";
		cur = cur->next;
	}
}

int main (){
	int  pilihan, nilai;
	
	do{
		cout<<"\nMenu"<<endl;
		cout<<"1. Node awal "<<endl;
		cout<<"2. tambahkan Node "<<endl;
		cout<<"3. hapus Node"<<endl;
		cout<<"4. tampilkan"<<endl;
		cout<<"5. Keluar "<<endl;
		cout<<"Masukkan pilihan [1..5]: ";
		cin>>pilihan;
		
		switch(pilihan){
			case 1:
				cout<<"Buat Node Awal"<<endl;
				cout<<"================="<<endl;
				cout<<"Masukkan Nilai : ";
				cin>>nilai;
				nodeAwal(nilai);
				break;
			case 2:
				cout<<"Tambahkan Node"<<endl;
				cout<<"================="<<endl;
				cout<<"Masukkan Nilai : ";
				cin>>nilai;
				tambahkanNode(nilai);
				break;
			case 3:
				cout<<"Hapus Node"<<endl;
				cout<<"================="<<endl;
				cout<<"Masukkan Nilai yang ingin dihapus: ";
				cin>>nilai;
				hapus(nilai);
				break;
			case 4:
				cout<<endl;
				tampilkan();
				break;
			case 5:
				cout<<"keluar dari program"<<endl;
				break;
			default:
				cout<<"Pilihan tidak valid"<<endl;
		}
	}while (pilihan != 5);
	return 0;
}
