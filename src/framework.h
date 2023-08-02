#ifndef framework_H
#define framework_H

#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
#include <pthread.h>
#include "conjeturaDebil.h"
#include "conjeturaFuerte.h"
#include <stdio.h>
#include "primeNumbers.h"
#include <fstream>

using namespace std::chrono;
using namespace std;

// * SW = Stopwatch
// ? | startSW()     : Begins Counting
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

// ? nThr = Number of threads(Limited to CPU cores)
// ? tMax = Limit of the range per thread
// ? tMin = The minimum number for the range per thread
unsigned int nThr = (thread::hardware_concurrency() > 0) ? thread::hardware_concurrency() : 2;
unsigned int tMax;
unsigned int tMin;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
vector<pthread_t> threads(nThr);


// * tArg: Arguments to be passed to either (strong/weak)Conjecture
struct tArg {
    vector<char> primes;
    int min;
    int max;
};


// * strongConjecture: Finds all pairs that are the sum of two primes between min-max
void strongConjecture(const vector<char>& primes, int min, int max)
{
    tMax = max/nThr;
    tMin = min;

    // ! Open threads
    vector<tArg> newArgs(nThr);
    for (int t = 0; t < nThr; ++t) {
        newArgs[t].primes = primes;
        newArgs[t].min = tMax*t;
        newArgs[t].max = tMax*(t+1);

        // ! Hard coded for some pair numbers that won't get up to the limit
        if(tMax%2 != 0 & t == nThr-1)
        {
            newArgs[t].max = max;
        }
        pthread_create(&threads[t], nullptr, strong, (void *)&newArgs[t]);
    }

    // ! Close threads
    for (int t = 0; t < nThr; ++t) {
        pthread_join(threads[t], nullptr);
        // cout << "Thread: " << threads[t] << endl; 
    }
}


// * weakConjecture: Finds all pairs that are the sum of three primes between min-max
void weakConjecture(const vector<char>& primes, int min, int max)
{
    weak(primes, min, max);
}

// * getPrimeNumbers: Gets all prime numbers between min-max
vector<char> getPrimeNumbers(int min, int max)
{
    vector<char> primes = getPrimes(min, max);
    return primes;
}

#endif