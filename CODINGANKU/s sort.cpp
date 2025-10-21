#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int &comparisons, int &swaps) {
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++; // Menghitung jumlah perbandingan
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) { // Hanya swap jika minIndex berubah
            swap(arr[i], arr[minIndex]);
            swaps++; // Menghitung jumlah pertukaran
        }
    }
}

int main() {
    int arr[] = {10, 5, 8, 3, 2}; // Sesuai dengan soal
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons, swaps;

    selectionSort(arr, n, comparisons, swaps);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons: " << comparisons;
    cout << "\nNumber of swaps: " << swaps << endl;

    return 0;
}

