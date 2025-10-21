#include <iostream>
using namespace std;

#define FAHRENHEIT_TO_CELCIUS
// #define CELCIUS_TO_FAHRENHEIT

#ifdef CELCIUS_TO_FAHRENHEIT
    #define C_TO_F(c) ((c * 9.0 / 5.0) + 32)
#endif

#ifdef FAHRENHEIT_TO_CELCIUS
    #define F_TO_C(f) ((f - 32) * 5.0 / 9.0)
#endif

int main() {
    double celcius, fahrenheit;

    cout << "Masukkan suhu celcius yang diketahui : ";
    cin >> celcius;

    cout << "Masukkan suhu fahrenheit yang di ketahui : ";
    cin >> fahrenheit;

#ifdef CELCIUS_TO_FAHRENHEIT
    cout << celcius << " derajat Celsius sama dengan " 
         << C_TO_F(celcius) << " derajat Fahrenheit.\n";
#else
    cout << "Rumus belum di define\n";
#endif

#ifdef FAHRENHEIT_TO_CELCIUS
    cout << fahrenheit << " derajat Fahrenheit sama dengan "
         << F_TO_C(fahrenheit) << " derajat Celsius.\n";
#else
    cout << "Rumus belum di define\n";
#endif

    return 0;
}

