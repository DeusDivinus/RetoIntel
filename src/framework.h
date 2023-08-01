#ifndef framework_H
#define framework_H

#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
#include "conjeturaDebil.h"
#include "conjeturaFuerte.h"
#include "primeNumbers.h"

using namespace std::chrono;
using namespace std;

// * SW = Stopwatch
// ? | startSW()     : Starts counting
// ? | showResult()  : Stops SW & Shows Result
class SW{
    private:
        high_resolution_clock::time_point start;
        high_resolution_clock::time_point stop;
        void stopSW(){
        stop = high_resolution_clock::now();
    };  
    public:
    void startSW(){
        start = high_resolution_clock::now();
    };  
    void showResult(){
        stopSW();
        auto duration = duration_cast<chrono::nanoseconds>(stop - start).count() * 1e-9;
        cout << "Time taken by program is : " << fixed
        << duration << setprecision(9);
        cout << " sec" << endl;
    }
};

// * strongConjecture: Finds all pairs that are the sum of two primes between min-max
void strongConjecture(const vector<char>& primes, int min, int max)
{
    strong(primes, min, max);
}

// * weakConjecture: Finds all pairs that are the sum of three primes between min-max
void weakConjecture(const vector<char>& primes, int min, int max)
{
    weak(primes, min, max);
}

// * getPrimeNumbers: Gets all prime numbers between min-max
vector<char> getPrimeNumbers(int min, int max)
{
    return getPrimes(min, max);
}
#endif