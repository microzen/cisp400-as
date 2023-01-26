//
// Created by Microzenas on 1/25/23.
// Assignment: https://lrccd.instructure.com/courses/183062/assignments/4743431?module_item_id=14449374
//
// TODO:

#include "RSA.h"

bool isPrime(unsigned long long n) {
    unsigned long long counter = 1;
    bool isPrime = true;
    while (counter < n) {
        if (n % counter == 0) {
            isPrime == false;
            break;
        }
        counter++;
    }
    return isPrime;
}
