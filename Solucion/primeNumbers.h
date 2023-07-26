#include <iostream>
#include <omp.h>
#include <ctime>
#include <bits/stdc++.h>
#include <list>
#include <fstream>
using namespace std;

#ifndef primeNumbers_H
#define primeNumbers_H
bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int getPrimes(int max)
{
    static long long int _index;
    static int state = 0;
    switch (state) {
    case 0:
        state = 1;
        for (_index = 2; _index < max; _index++) {
            if (isPrime(_index)){
            return _index;
            }

        case 1:
            continue;
        }
    }
    state = 0;
    return 0;
}
#endif
