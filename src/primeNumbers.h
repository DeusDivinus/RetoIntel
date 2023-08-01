#ifndef primeNumbers_H
#define primeNumbers_H

#include <iostream>
#include <omp.h>
using namespace std;

// ! Modified from https://www.geeksforgeeks.org/sum-of-all-the-prime-divisors-of-a-number/
// ?    | n: Any integer
// Returns true, false = prime, not prime
char isPrime(int n) {
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// * getPrimes: returns a list between min, max, which each prime index is 1
// ?    | min: Any integer, must be below max
// ?    | max: Any integer, must be above min
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
