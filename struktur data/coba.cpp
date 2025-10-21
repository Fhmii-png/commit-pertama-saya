#include<iostream>
using namespace std;

struct Node{
	int nilai;
	
	Node *next;
};

Node *head =NULL;

void nodeAwal(int nilai){
	if (head != NULL){
		cout<<"Node awal sudah ada"<<endl;
		return;
	}
	head = new Node();
	head->nilai=nilai;
	head->next=NULL;
	cout<<"Nilai"<<nilai<<"berhasil ditambahkan"<<endl;
}
void tambahNode(int nilai){
	if (head == NULL){
		cout<<"Lnked list kosong, isi node awal dulu"<<endl;
		return;
	}
	Node *baru = new Node();
	baru->nilai=nilai;
	baru->next = NULL;
	
	Node *cur = head;
	while(cur->next != NULL){
		cur=cur->next;
	}
	cur->next=baru;
	cout<<"Node dengan Nilai "<<nilai<<"berhasil ditambahkan"<<endl;
}
void hapusNode(int nilai){
	if (head == NULL){
		cout<<"Linked List kosong"<<endl;
		return;
	}
	Node *cur = head;
	Node *prev = NULL;
	while(cur != NULL && cur->nilai != nilai){
		prev = cur;
		cur=cur->next;
	}
	if (cur == NULL){
		cout<<"List Kosong"<<nilai<<"tidak dapat ditemukan"<<endl;
		return;
	}
	if (prev == NULL){
		head = head->next;
	}
	else{
		prev ->next = cur->next;
	}
	delete cur;
	cout<<"Node dengan nilai"<<nilai<<"berhasil dihapus"<<endl;
}
void tampilkan(){
	if(head == NULL){
		cout<<"Linked list Kosong"<<endl;
		return;
	}
	Node *cur = head;
	cout<<"isi linked list"<<endl;
	cout<<"==============="<<endl;
	while(cur != NULL){
		cout<<cur->nilai<<" ";
		cur = cur->next;
	}
	cout<<endl;
}
int main(){
	int pilihan, nilai;
	
	do{
		cout<<"\n Menu"<<endl;
		cout<<"1. Node awal"<<endl;
		cout<<"2. tambahkan Node"<<endl;
		cout<<"3. hapus node"<<endl;
		cout<<"4. Tampilkan "<<endl;
		cout<<"5. keluar"<<endl;
		cout<<"Masukkan pilihan [1..5]: ";
		cin>>pilihan;
		
		switch (pilihan){
			case 1:
				cout<<"buat Node Awal"<<endl;
				cout<<"=============="<<endl;
				cout<<"masukkan nilai: ";
				cin>>nilai;
				nodeAwal(nilai);
				break;
				
			case 2: 
			
				cout<<"Tambahkan Node"<<endl;
				cout<<"=============="<<endl;
				cout<<"masukkan nilai: ";
				cin>>nilai;
				tambahNode(nilai);
				break;
		
			case 3:
				
				cout<<"hapus Node"<<endl;
				cout<<"=============="<<endl;
				cout<<"masukkan nilai: ";
				cin>>nilai;
				hapusNode(nilai);
				break;
		
			case 4:
				cout<<endl;
				tampilkan();
				break;
			case 5:
				cout<<"keluar dari program ";
				break;
			default:
				cout<<"Pilihan tidak valid";
		
		}
	}while (pilihan != 5);
	return 0;
}
