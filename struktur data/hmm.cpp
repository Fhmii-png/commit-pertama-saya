#include<iostream>
using namespace std;

struct Node {
	int nilai ;
	
	Node *next;
};

Node *head = NULL;

void nodeAwal (int nilai ){
	if (head != NULL){
		cout<<"Node Awal Sudah Ada"<<endl;
		return ;
	}
	head = new Node();
	head -> nilai = nilai;
	head->next =NULL;
	cout<<" Node dengan Nilai "<<nilai <<" Berhasil Ditambahkan"<<endl;
	
}
void tambahNode(int nilai){
	if (head == NULL){
		cout<<"Linked List kosong, isi Node awal dulu"<<endl;
		return;
	}
	Node *baru = new Node();
	baru ->nilai = nilai;
	baru ->next = NULL;
	
	Node *cur = head;
	while (cur->next != NULL){
		cur = cur->next;
	}
	cur->next = baru;
	cout<<"Node dengan Nilai"<<nilai <<"Berhasil ditambahkan"<<endl;
	
}
void hapusNode(int nilai){
	if (head == NULL){
		cout<<" linked list kosong"<<endl;
		return;
	}
	Node *cur = head;
	Node *prev = NULL;
	
	while(cur != NULL && cur->nilai != nilai){
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL){
		cout<<"list masih kosong"<<nilai<<"tidak ditemukan"<<endl;
		return;
	}
	if(prev == NULL){
		head = head->next;
	}
	else {
		prev->next = cur->next;
	}
	delete cur;
	cout<<"Node dengan nilai "<<nilai<<"berhasil dihapus"<<endl;
}
		

void tampilkan(){
	if (head == NULL){
		cout<<"Isi Linked List"<<endl;
		return;
	}
	Node *cur = head;
	cout<<"isi Linked List"<<endl;
	cout<<"==============="<<endl;
	while(cur != NULL){
		cout<<cur->nilai<<" ";
		cur = cur ->next;
	}
	cout<<endl;
}
int main (){
	int pilihan, nilai;
	
	do {
		cout<<"\Menu"<<endl;
		cout<<"1. Node Awal"<<endl;
		cout<<"2. tambahkan Node"<<endl;
		cout<<"3. Hapus Node "<<endl;
		cout<<"4. Tampilkan"<<endl;
		cout<<"5. keluar"<<endl;
		cout<<"Masukkan Pilihan [1..5]: ";
		cin>>pilihan;
		
		switch (pilihan){
			case 1:
				cout<<"Node Awal"<<endl;
				cout<<"=========="<<endl;
				cout<<"Masukkan nilai: ";
				cin>>nilai;
				nodeAwal(nilai);
				break;
				
			case 2:
				cout<<"Tambahkan Node"<<endl;
				cout<<"=========="<<endl;
				cout<<"Masukkan nilai: ";
				cin>>nilai;
				tambahNode(nilai);
				break;
			case 3:
				cout<<"Hhapus Node"<<endl;
				cout<<"=========="<<endl;
				cout<<"Masukkan nilai: ";
				cin>>nilai;
				hapusNode(nilai);
				break;
			case 4:
				cout<<endl;
				tampilkan();
				break;
			case 5:
				cout<<"keluar dari program...."<<endl;
				break;
			default:
				cout<<"pilihan tidak valid"<<endl;
		}
		
		
	}while (pilihan != 5);
}

