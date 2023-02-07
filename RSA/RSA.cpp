//
// Created by Microzenas on 1/25/23.
// Assignment: https://lrccd.instructure.com/courses/183062/assignments/4743431?module_item_id=14449374
//
// TODO:

#include <random>
#include "RSA.h"

bool isPrime(unsigned long long n)
{

    if(n == 1) return false;
    else if(n == 2) return true;
    else if(n % 2 == 0) return false;

    for (long i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}

unsigned long long getPrime(unsigned long long min, unsigned long long max)
{

    unsigned long long number = 0;
    bool is_prime = false;
    while (!is_prime)
    {
        number = (rand() % (max - min + 1)) + min;
        is_prime = isPrime(number);
    }
    return number;
}

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    if (x % y == 0)
    {
        return y;
    }
    else
    {
        return gcd(y, x % y);
    }
}

unsigned long long lcm(unsigned long long x, unsigned long long y)
{
    return (x * y) / gcd(x, y);
}

unsigned long long modInverse(unsigned long long e, unsigned long long lam)
{
    for (unsigned long long i = 1; i < lam; ++i)
    {
        if ((e * i) % lam == 1)
        {
            return i;
        }
    }
    return 0;
}

unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long n)
{
    unsigned long long ans = 1;
    for (unsigned long long i = 0; i < exp; i++)
        ans = (ans * base) % n;
    return ans;
}
