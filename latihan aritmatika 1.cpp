#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double panjang;
    double lebar;
    double tinggi;
    cout << "Panjang : ";
    cin >> panjang;
    
    cout << "Lebar : ";
    cin >> lebar;
    
    cout << "Tinggi : ";
    cin >> tinggi;
    
    double volume = panjang * lebar * tinggi;
    cout << "Volume : " << volume;
    cout << endl;

    return 0;
}

