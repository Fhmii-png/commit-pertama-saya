#include <iostream>
using namespace std;

// Fungsi merge untuk Merge Sort
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (*(L + i) <= *(R + j)) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(arr + k) = *(L + i);
        i++;
        k++;
    }

    while (j < n2) {
        *(arr + k) = *(R + j);
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Merge Sort
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Binary Search
int binarySearch(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (*(arr + mid) == target)
            return mid;
        else if (*(arr + mid) < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Fungsi utama
int main() {
    const int n = 8;
    int data[n] = {24, 17, 39, 2, 15, 89, 7, 6};

    cout << "Data sebelum sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << *(data + i) << " ";
    }

    mergeSort(data, 0, n - 1);

    cout << "\n\nData setelah merge sort:\n";
    for (int i = 0; i < n; i++) {
        cout << *(data + i) << " ";
    }

    int target;
    cout << "\n\nMasukkan angka yang ingin dicari: ";
    cin >> target;

    int result = binarySearch(data, 0, n - 1, target);
    if (result != -1)
        cout << "Angka ditemukan di indeks ke-" << result << endl;
    else
        cout << "Angka tidak ditemukan.\n";

    return 0;
}

