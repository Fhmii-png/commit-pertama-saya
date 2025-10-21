#include<iostream>
using namespace std;

struct buku{
    string judul, pengarang;
    int tahunTerbit;

    buku *next;
};

buku *head, *tail, *cur, *newNode;

void buatlinkedlist( string judul, string pengarang, int tahunTerbit){
	head = new buku();
	head->judul = judul;
	head->pengarang= pengarang;
	head->tahunTerbit=tahunTerbit;
	head->next= NULL;
	tail = head;

}
void buatlink1( string judul, string pengarang, int tahunTerbit){
	newNode= new buku();
	newNode->judul = judul;
	newNode->pengarang= pengarang;
	newNode->tahunTerbit=tahunTerbit;
	newNode->next= head;
	head = newNode;
}
void buatlink2( string judul, string pengarang, int tahunTerbit){
	newNode= new buku();
	newNode->judul = judul;
	newNode->pengarang= pengarang;
	newNode->tahunTerbit=tahunTerbit;
	newNode->next= NULL;
	tail->next=newNode;
	tail = newNode;
}


void printlink(){
	cur = head;
	while(cur != NULL){
		cout<<"Judul Buku: "<<cur->judul<<endl;
		cout<<"pengarang: "<<cur->pengarang<<endl;
		cout<<"Tahun Terbit: "<<cur->tahunTerbit<<endl;
		cout<<endl;
		cur = cur->next;
	}

}
int main(){
	buatlinkedlist ("pelangi", "fhmiii", 2011);
	buatlink1 ("matahari", "jarjit", 2005);
	
	printlink();   
	cout<<endl;
	


}
