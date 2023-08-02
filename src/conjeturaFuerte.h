#ifndef conjeturaFuerte_H
#define conjeturaFuerte_H

#include <iostream>
#include <omp.h>
#include <fstream>

using namespace std;

struct strongArgs {
    vector<char> primes;
    int min;
    int max;
};

// * strong: get the pairs that are the sum of two primes
// ?    | args:  [strongArgs]
// ?        | min = Min number of the range
// ?        | max = Max number of the range
// ?        | primes: list of primes, which index is equal to 1 if prime
void* strong(void *args) {
    struct strongArgs *newArgs = (struct strongArgs*)args;
    vector<char>& primes = newArgs->primes;
    unsigned int maxV = newArgs->max;
    unsigned int minV = newArgs->min;
    unsigned int result;

    // ! Open file to append
    ofstream MyFile("primePairs.txt", fstream::app);

    #pragma omp parallel for schedule(dynamic)
    for(unsigned int x = minV; x <= maxV; ++x) {
        // * Skipping unnecesary iterations
        if(x%2)
        {
            continue;
        }
        // * Iterate through all numbers, and compare to each index of prime
        // *    If N - Prime = Prime, then N = Prime + Prime
        for(unsigned int y = 2; y <= x/2; ++y){
            unsigned int result = x-y;
            if(primes[result] & (y%2 != 0 | y == 2))
            {
                // ! Write combination to file
                #pragma omp critical
                MyFile << x << "=" << y << "+" << result << "\n";
            }
        }
    }
    // ! Close file
    MyFile.close();
}

#endif