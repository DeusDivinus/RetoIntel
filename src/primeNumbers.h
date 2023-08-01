#include <iostream>
#include <omp.h>
#include <ctime>
#include <bits/stdc++.h>
#include <list>
#include <fstream>
#include "framework.h"
using namespace std;

#ifndef primeNumbers_H
#define primeNumbers_H
SW pnSW;
char isPrime(int n) {
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return 1;
}

vector<char> getPrimes(int min, int max)
{
    vector<char> primesBool(max + 1, 0);
    primesBool[2] = 1;
    #pragma omp parallel for schedule(dynamic)
    for (unsigned int i = min; i <= max; i++) {
        if(i%2 != 0)
        {
            primesBool[i] = isPrime(i);
        }
    }
    return primesBool;
}
#endif
