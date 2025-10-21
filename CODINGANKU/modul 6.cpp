#include <iostream>
using namespace std;

int partition(int a[], int start, int end) {
    int pivot = a[end];
    int partitionIndex = start;

    for (int i = start; i < end; i++) {
        if (a[i] < pivot) {
            swap(a[i], a[partitionIndex]);
            partitionIndex++;
        }
    }

    swap(a[partitionIndex], a[end]);
    return partitionIndex;
}


void quickSort(int a[], int start, int end) {
    if (start < end) {
        int partitionIndex = partition(a, start, end);
        quickSort(a, start, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, end);
    }
}

int binarySearch(int a[], int n, int x) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (a[mid] == x) return mid;
        else if (x < a[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[100];
    cout << "Masukkan elemen-elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    
    int minValue = arr[0];
    
    binarySearch (arr, n, minValue);

    cout << "\nArray yang diinput : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nNilai minimum yang ditemukan: " << minValue;

    return 0;
}

