#include<iostream>
using namespace std;

struct barang{
	string nama;
	int jumlah;
	
	barang *next;
};

barang *head, *tail, *cur;

void createSingleLinkedList(string nama, int jumlah){
	head = new barang();
	head->nama= nama;
	head->jumlah = jumlah;
	head->next = NULL;
	tail = head;
}
	
void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout<<"Nama Brang: "<<cur->nama<<endl;
		cout<<"Jumlah Barang: "<<cur->jumlah<<endl;
		cout<<endl;
		cur = cur->next;
	}
			
}
int main (){
	createSingleLinkedList ("pelangi", 20);
	
	printSingleLinkedList();
	
}