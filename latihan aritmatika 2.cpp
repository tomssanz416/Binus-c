#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14

int main() {
    double jari;
    cout << "Jari-jari : ";
    cin >> jari;
    

	double volume_bola = PI * pow(jari, 2);
    cout << "Volume : " << volume_bola;
    cout << endl;

    return 0;
}

