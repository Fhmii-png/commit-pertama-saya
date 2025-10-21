#include <iostream>
using namespace std;

int perbandingan = 0;
int pertukaran = 0;

void merge(int arr[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    int* kiriArr = new int[n1];
    int* kananArr = new int[n2];

    for (int i = 0; i < n1; i++)
        kiriArr[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++)
        kananArr[j] = arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;

    while (i < n1 && j < n2) {
        perbandingan++;
        if (kiriArr[i] <= kananArr[j]) {
            arr[k] = kiriArr[i];
            i++;
        } else {
            arr[k] = kananArr[j];
            j++;
            pertukaran += (n1 - i); // elemen dari kiri yang tersisa akan "tergeser"
        }
        k++;
    }

    while (i < n1) {
        arr[k] = kiriArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = kananArr[j];
        j++;
        k++;
    }

    delete[] kiriArr;
    delete[] kananArr;
}

void mergeSort(int arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);
        merge(arr, kiri, tengah, kanan);
    }
}


int main() {
    int arr[100], n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nArray awal: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    mergeSort(arr, 0, n - 1);

    cout << "\nHasil Merge Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nJumlah perbandingan: " << perbandingan << endl;
    cout << "Jumlah pertukaran: " << pertukaran << endl;

    return 0;
}

