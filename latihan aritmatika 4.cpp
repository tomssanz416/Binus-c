#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double A;
    cout << "Nilai A : ";
    cin >> A;
    
    double B;
    cout << "Nilai B : ";
    cin >> B;
    
    double C;
    cout << "Nilai C : ";
    cin >> C;
    
	double diskriminan = pow(B, 2) - 4 * A * C;
    cout << "D : " << diskriminan;
    cout << endl;

    return 0;
}

