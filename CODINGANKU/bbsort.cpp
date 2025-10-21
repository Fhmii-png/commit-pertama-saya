#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    int swapCount = 0, compareCount = 0;

    cout << "\nProses Bubble Sort" << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << "Iterasi " << i + 1 << ": ";
        for (int j = 0; j < n - 1 - i; j++) {
            compareCount++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    
        for (int k = 0; k < n; k++) {
            cout << "[" << arr[k] << "] ";
        }
        cout << endl;
    }

    cout << "\nData yang telah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nJumlah perbandingan: " << compareCount;
    cout << "\nJumlah pertukaran: " << swapCount << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah data = ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Masukkan data ke-" << i + 1 << " = ";
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    return 0;
}

