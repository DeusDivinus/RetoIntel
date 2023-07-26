#include <iostream>
#include <omp.h>
#include <ctime>
#include <bits/stdc++.h>
#include <list>
using namespace std;

static int _length = 0;
static int _Primos[]{};

void appendArray(int value){
    _Primos[_length] = value;
    _length++;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

int* getPrimes(int limit){
    _length = 0;

    for(int i = 0; i < limit; i++)
    {
        if (isPrime(i)){
            appendArray(i);
        }
    }
    cout << _length << endl;
    return _Primos;
}
