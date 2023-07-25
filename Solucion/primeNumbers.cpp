#include <iostream>
#include <omp.h>
#include <ctime>
#include <bits/stdc++.h>
#include <list>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

void* getPrimes(int primesList[], int limit){
    string e;
    // for(int i = 0; i < limit; i++)
    // {
    //     // if (isPrime(i)){

    //     // }
    // }
    return 0;
}

