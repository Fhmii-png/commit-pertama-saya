#include <iostream>
using namespace std;

int perbandingan = 0, pertukaran = 0;
int temp[100];

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        perbandingan++;  // ? tambahkan di sini, PASTI dibandingkan
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[100], n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nArray awal: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    mergeSort(arr, 0, n - 1);

    cout << "\nHasil Merge Sort: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    cout << "\n\nJumlah perbandingan: " << perbandingan;
    cout << "\nJumlah pertukaran: " << pertukaran << endl;

    return 0;
}

