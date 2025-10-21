#include<iostream>
using namespace std;

struct buku{
	string judul, pengarang;
	int tb;
	
	buku *next;
};

buku *head, *tail, *cur, *newNode, *del;

void buat(string judul, string pengarang, int tb){
	head = new buku();
	head->judul= judul;
	head->pengarang= pengarang;
	head->tb=tb;
	head->next=NULL;
	tail = head;
}
void buat1(string judul, string pengarang, int tb){
	newNode = new buku();
	newNode -> judul=judul;
	newNode->pengarang=pengarang;
	newNode->tb=tb;
	newNode->next= head;
	head=newNode;
}
void buat2(string judul, string pengarang, int tb){
	newNode = new buku();
	newNode -> judul= judul;
	newNode -> pengarang= pengarang;
	newNode->tb=tb;
	newNode->next=NULL;
	tail->next=newNode;
	tail = newNode;
	
}
void hapusawal(){
	del = head;
	head=head->next;
	delete del;
	cout<<endl;
	
}
void hapusakhir(){
	del = tail;
	cur=head;
	while(cur->next != tail){
		cur = cur->next;
		
	}
	tail = cur;
	cur->next = NULL;
	delete del;
	cout<<endl;
}
void tambahkan(){
	cur = head;
	while(cur != NULL){
		cout<<"judul: "<<cur->judul<<endl;
		cout<<"pengarang: "<<cur->pengarang<<endl;
		cout<<"tahun Terbit: "<<cur->tb<<endl;
		cur= cur->next;
	}
}
int main(){
	buat ("Alpro", "Fhmii", 2010);
	buat1 ("Basis", "jarjit", 2009);
	buat2 ("SD", "syariful", 2019);
	tambahkan ();
	hapusakhir();
	tambahkan();
}

