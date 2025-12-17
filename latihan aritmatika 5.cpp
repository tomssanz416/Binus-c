#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double x1;
    cout << "Nilai x1 : ";
    cin >> x1;
    
    double x2;
    cout << "Nilai x2 : ";
    cin >> x2;
    
    double y1;
    cout << "Nilai y1 : ";
    cin >> y1;
    
    double y2;
    cout << "Nilai y2 : ";
    cin >> y2;
    
    double delta_x = x2 - x1;
    double delta_y = y2 - y1;
    double jarak = 111 * sqrt((pow(delta_x, 2)) + (pow(delta_y, 2)));
    cout << "Jarak : " << jarak;
    cout << endl;

    return 0;
}

