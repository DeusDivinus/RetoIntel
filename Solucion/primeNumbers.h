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
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

vector<bool> getPrimes(int min, int max)
{
    vector<bool> primesBool(max + 1, true);
    #pragma omp parallel for schedule(dynamic)
    for (int i = min; i <= max; i++) {
        primesBool[i] = isPrime(i);
    }
    return primesBool;
}
#endif
