#ifndef conjeturaFuerte_H
#define conjeturaFuerte_H

#include <iostream>
#include <omp.h>
using namespace std;
void checkPairsLeft(const vector<char>& pairs, unsigned int max) {
    cout << "Pairs left to get: ";
    unsigned int left = 0;
    for (unsigned int i = 2; i <= max; i += 2) {
        if(pairs[i] == 0) {
            ++left;
            cout << i << endl;
        }
    }
    cout << left << endl;
} 

void strong(const vector<char>& primes, int min, int max) {
    vector<char> pairs(max+1, 0);
    unsigned int result;
    pairs[2] = 1;
    for (unsigned int i = 0; i <= max; ++i) {
        result = i*2;
        if (primes[i] & (result % 2 == 0) & result < max){
            pairs[result] = 1;
        }
        if(i < 4 | i%2 != 0 | pairs[i])
        {
            continue;
        }
        for (unsigned int v = 0; v <= max; ++v){
            if(v%2 == 0)
            {
                continue;
            }
            result = i-v;
            if(primes[v] & primes[result])
            {
                pairs[result+v] = 1;
                break;
            }
        }
    }
    checkPairsLeft(pairs, max);
}
#endif