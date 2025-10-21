#include <iostream>
using namespace std;


int k(int n, int r) {
    
    if (r == 0 || r == n) {
        return 1;
    }
    return k(n - 1, r - 1) + k(n - 1, r);
}

int main() {
    int n, r;

    cout << "Masukkan nilai n: ";
    cin >> n;
    cout << "Masukkan nilai r: ";
    cin >> r;
	
    cout << "C(" << n << ", " << r << ") = " << k(n,r) << endl;

}


