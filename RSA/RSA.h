//
// Created by Microzenas on 1/25/23.
//

#ifndef ASSIGNMENTS_RSA_H
#define ASSIGNMENTS_RSA_H
bool isPrime(unsigned long long n);
unsigned long long getPrime(unsigned long long min, unsigned long long max);
unsigned long long gcd(unsigned long long x, unsigned long long y);
unsigned long long lcm(unsigned long long x, unsigned long long y);
unsigned long long modInverse(unsigned long long e, unsigned long long lam);
unsigned long long modExp(unsigned long long base,unsigned long long exp,unsigned long long n);
#endif //ASSIGNMENTS_RSA_H