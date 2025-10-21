#include <iostream>
using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {5, 4, 3, 2, 1};
    int hasil[5];
    int *pa = a, *pb = b, *ph = hasil;

    for (int i = 0; i < 5; i++) {
        *(ph + i) = *(pa + i) * *(pb + i);
    }

    cout << "Hasil perkalian array: ";
    for (int i = 0; i < 5; i++) {
        cout << hasil[i] << " ";
    }
    cout << endl;
    return 0;
}

