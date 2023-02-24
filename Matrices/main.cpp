#include "Matrices.h"
int main(){
    Matrices::Matrix a(2, 2);
    Matrices::Matrix b(2, 4);

    a(0, 0) = 0;
    a(0, 1) = -1;
    a(1, 0) = 1;
    a(1, 1) = 0;

    cout << "a:" << endl << a << endl;

    b(0, 0) = 1;
    b(0, 1) = 0.866025;
    b(0, 2) = 1;
    b(0, 3) = 0.5;
    b(1, 0) = 0;
    b(1, 1) = 0.5;
    b(1, 2) = 1;
    b(1, 3) = 0.866025;

    cout << "\nb:" << endl << b << endl ;

    Matrices::Matrix c(2, 4);
    c = b + b;
    cout << "\nc = b + b:"<< endl << c << endl;

    c = a * b;
    cout<< "\nc = a * b:" <<endl<< c << endl;
}