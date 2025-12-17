#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14

int main() {
    double jari;
    cout << "Jari-jari : ";
    cin >> jari;
    
    double tinggi;
    cout << "tinggi : ";
    cin >> tinggi;
    
	double volume_tabung = PI * pow(jari, 2) * tinggi;
    cout << "Volume : " << volume_tabung;
    cout << endl;

    return 0;
}

