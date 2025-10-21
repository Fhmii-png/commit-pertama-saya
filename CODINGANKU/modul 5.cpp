#include <iostream>
using namespace std;

// Fungsi Quick Sort
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

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

// Fungsi Linear Search
int linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (x == a[i])
            return i;
    }
    return -1;
}

// Fungsi Iterative Binary Search
int binarySearchIterative(int a[], int n, int x) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (x == a[mid])
            return mid;
        else if (x < a[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

// Fungsi Recursive Binary Search
int binarySearchRecursive(int a[], int start, int end, int x) {
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (x == a[mid])
        return mid;
    else if (x < a[mid])
        return binarySearchRecursive(a, start, mid - 1, x);
    else
        return binarySearchRecursive(a, mid + 1, end, x);
}

int main() {
    int n;
    cout << "Masukkan kapasitas array a[] : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "Masukkan angka ke-" << i+1 << " : ";
        cin >> a[i];
    }

    quickSort(a, 0, n-1);

    cout << "\nData dalam array a[] setelah diurutkan :\n";
    cout << "a[" << n << "] = {";
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n-1) cout << ", ";
    }
    cout << "}\n\n";

    cout << "Pencarian data:\n";
    cout << "1. Algoritma Sequential/Linear Search\n";
    cout << "2. Algoritma Iterative Binary Search\n";
    cout << "3. Algoritma Recursive Binary Search\n";
    cout << "Masukkan pilihan [1..3]: ";
    int pilihan;
    cin >> pilihan;
    cout << "\n";

    if (pilihan == 1) {
        cout << "Pencarian dengan Linear Search\n";
    } else if (pilihan == 2) {
        cout << "Pencarian dengan Binary Search Iteratif\n";
    } else if (pilihan == 3) {
        cout << "Pencarian dengan Binary Search Rekursif\n";
    }

    cout << "============================================\n";

    int x;
    cout << "Masukkan angka yang dicari : ";
    cin >> x;

    cout << "Hasil : ";
    int index = -1;

    if (pilihan == 1) {
        index = linearSearch(a, n, x);
    }
    else if (pilihan == 2) {
        index = binarySearchIterative(a, n, x);
    }
    else if (pilihan == 3) {
        index = binarySearchRecursive(a, 0, n-1, x);
    }
    else {
        cout << "Pilihan tidak valid!\n";
        return 0;
    }

    if (index != -1) {
        cout << "Data ditemukan...\n";
        cout << "Indeks : " << index << endl;
    } else {
        cout << "Data tidak terdapat dalam array...\n";
    }

    return 0;
}

