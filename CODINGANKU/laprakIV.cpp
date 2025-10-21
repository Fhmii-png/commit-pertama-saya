#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];
    
    for (int i = 0; i < n; i++) {
    	cout<<"Masukkan data ke- "<<i+1<<" = ";
        cin >> arr[i];
    }

    int comparison = 0; 
    int shift = 0;      

  
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

      
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparison++;
            shift++;
        }
        if (j >= 0) comparison++; 

        arr[j + 1] =key;
        shift++;
    }

    cout << "\nArray setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nJumlah perbandingan: " << comparison;
    cout << "\nJumlah pergeseran: " << shift << endl;

    return 0;
}

