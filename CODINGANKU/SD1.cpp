//Muh. Fahmi Ashar
//1302024033 (A1)

// Kasus: Mengubah Suhu Fahrenheit ke Celcius 
#include<iostream>
using namespace std;

int main (){
	const int jumlahSuhu = 5;
	float fahrenheit[jumlahSuhu];
	float celcius[jumlahSuhu];
	
	cout<<"Masukkan "<< jumlahSuhu<<"Suhu dalam Fahrenheit:\n";
	for (int i=0; i<jumlahSuhu; i++){
		cout<<"Suhu Ke-"<<(i+1)<<": ";
		cin>> fahrenheit[i];
	}
	cout<<"\nHasil konversi Fahrenheit ke celcius:\n";
	for (int i=0; i<jumlahSuhu; i++){
		celcius [i]=(5.0/9)*(fahrenheit[i]-32);
	}
	cout<<"\nHasil Konversi Fahrenheit ke Celcius:\n";
	for(int i=0; i<jumlahSuhu; i++){
		cout<<"Fahrenheit: "<<fahrenheit[i]<<" ->Celcius: "<<celcius[i]<<char(248)<<"C"<<endl; 
		//char(248) untuk simbol derajatnya 
	}
	
	return 0;
}
