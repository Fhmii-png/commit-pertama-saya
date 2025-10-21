#include<iostream>
using namespace std;

#define Celcius(a)(((a *9)/5)+32)
#define Fahrenheit(a)(((a-32)*5)/9)

int main(){
    float C, F;
    
    cout << "Masukkan suhu Celcius yang diketahui: ";
        cin >> C;
    cout << "\n\nMasukkan suhu Fahrenheit yang diketahui: ";
        cin >> F;
        
    #ifdef Celcius
    cout << C << " derajat Celsius sama dengan " << Celcius(C) << " derajat Fahrenheit "<< endl;
    #else
    cout << "Rumus belum di define" << endl;
    #endif
    
    #ifdef Fahrenheit
    cout << F << " derajat Fahrenheit sama dengan " << Fahrenheit(F) << " derajat Celcius "<< endl;
    #else
    cout << "Rumus belum di define" << endl;
    #endif
    
    
    return 0;
}
