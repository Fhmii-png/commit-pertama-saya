#include<iostream>
using namespace std;

void c(int i, int a = 0, int b = 1) {
    if (a > i) 
	return;
    cout << a << " ";
    c(i, b, a + b);
}

int main() {
    int b;
    
    cout << "Masukkan nilai batas: ";
    cin >> b;
    
    c (b);
}


