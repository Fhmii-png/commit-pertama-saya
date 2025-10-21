#include<iostream>
using namespace std;

void selectionSort (int arr[], int n) {
    int compareCount = 0, swapCount = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndx = i;
        for (int j = i + 1; j < n; j++) {
            compareCount++;
            if (arr[j] < arr[minIndx]) {
                minIndx = j;
                
                
            }
        }

        if (minIndx != i) {
            swap (arr[i], arr[minIndx]);
            swapCount++;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons: " << compareCount;
    cout << "\nNumber of swaps: " << swapCount << endl;
}

int main() {
    int arr[] = {10, 5, 8, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    return 0;
}

