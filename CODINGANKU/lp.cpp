#include <iostream>
#include <stack>
using namespace std;


int compRec = 0, swapRec = 0;
int compItr = 0, swapItr = 0;


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    swapRec++;
}


void swapItrFunc(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    swapItr++;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        compRec++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


int partitionItr(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        compItr++;
        if (arr[j] <= pivot) {
            i++;
            swapItrFunc(arr[i], arr[j]);
        }
    }
    swapItrFunc(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}


void quickSortIterative(int arr[], int l, int h) {
    stack<int> s;
    s.push(l);
    s.push(h);

    while (!s.empty()) {
        h = s.top(); s.pop();
        l = s.top(); s.pop();

        int p = partitionItr(arr, l, h);

        if (p - 1 > l) {
            s.push(l);
            s.push(p - 1);
        }
        if (p + 1 < h) {
            s.push(p + 1);
            s.push(h);
        }
    }
}


int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr1[n], arr2[n];
    cout << "Masukkan elemen-elemen array:";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i]; 
    }

    cout << "\nArray Awal: ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl;

 
    quickSortRecursive(arr1, 0, n - 1);
    cout << "\nHasil Quick Sort Recursive: ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << "\nJumlah Perbandingan (Recursive): " << compRec;
    cout << "\nJumlah Pertukaran (Recursive): " << swapRec << endl;

   
    quickSortIterative(arr2, 0, n - 1);
    cout << "\nHasil Quick Sort Iterative: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << "\nJumlah Perbandingan (Iterative): " << compItr;
    cout << "\nJumlah Pertukaran (Iterative): " << swapItr << endl;

    return 0;
}

