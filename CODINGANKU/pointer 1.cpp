#include<iostream>
using namespace std;

int main(){
	int a;
	int *ptr =&a;
	*ptr = 10;
	cout<<"Nilai variabel a melalui pointer: "<< *ptr << endl;
	return 0;
	
}
