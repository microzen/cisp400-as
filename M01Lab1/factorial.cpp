//
// Created by Microzenas on 1/23/23.
//
#include "functions.h"
int factorial(int n)
{
    if(n>=1)
        return(n * factorial(n-1));
    else
        return 1;
}