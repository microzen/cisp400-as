//
// Created by Microzenas on 1/29/23.
//
#include <random>
#include <climits>
#include <iostream>
#include "RSA.h"

using namespace std;

int main() {
    unsigned long long p, q, n, lambda, d, e, m, c;

    int seed;

    cout << "Enter a seed: ";
    cin >> seed;

    srand(seed);

    p = getPrime(UCHAR_MAX, USHRT_MAX);
    do {
        q = getPrime(UCHAR_MAX, USHRT_MAX);
    } while (p == q);

    cout << "\np: " << p << endl;
    cout << "q: " << q << endl;

    n = p * q;
    cout << "n: " << n << endl;

//    lambda = (p - 1) * (q - 1);
    lambda = lcm(p - 1, q - 1);

    cout << "lambda: " << lambda << endl;

    do {
        e = getPrime(2, lambda - 1);
    } while (lambda % e == 0);
    cout << "e: " << e << endl;

    d = modInverse(e, lambda);
    cout << "d: " << d << endl;

    cout << "Public key: n = " << n << " e = " << e << endl;
    cout << "Private key: n = " << n << " d = " << d << endl;

    cout << "Enter a positive number less than " << n << ": ";
    cin >> m;

    c = modExp(m, e, n);
    cout << "\nCipher: " << c << endl;

    cout << "Decrypted cipher: " << modExp(c, d, n);

    return 0;
}