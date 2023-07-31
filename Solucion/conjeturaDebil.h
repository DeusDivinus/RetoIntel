#include <iostream>
#include <omp.h>
#include "primeNumbers.h"
using namespace std;

#ifndef conjeturaDebil_H
#define conjeturaDebil_H
void checkLeft(const vector<char> &unpairs, unsigned int max)
{
    cout << "Unpairs left to get: ";
    unsigned int left = 0;
    for (unsigned int i = 1; i <= max; i += 2)
    {
        if (unpairs[i] == 0)
        {
            cout << i << endl;
            ++left;
        }
    }
    cout << left << endl;
}

void weak(const vector<char> &primes, int min, int max)
{
    vector<char> unpairs(max + 1, 0);
    unsigned int result;
    unsigned int resultY;
    unsigned int resultZ;
    unpairs[5] = 1;
    unpairs[3] = 1;
    unpairs[1] = 1;
    for (unsigned int i = 0; i <= max; ++i)
    {
        result = i * 3;
        resultY = i * 2;
        if (primes[i] & (result % 2 != 0) & result < max)
        {
            resultY = resultY+(i+2);
            unpairs[result] = 1;
            unpairs[resultY] = 1;
        }
        if (i < 5 | i % 2 == 0 | unpairs[i])
        {
            continue;
        }
        for (unsigned int v = 0; v <= max; ++v)
        {
            result = i - v;
            if (result > max | unpairs[i])
            {
                break;
            }
            if (!primes[v] | i % 2 == 0)
            {
                continue;
            }

            for (unsigned int z = 0; z <= max; ++z)
            {
                resultZ = result - z;
                if (resultZ > max)
                {
                    break;
                }
                if (!primes[z] | !primes[resultZ])
                {
                    continue;
                }
                unpairs[resultZ+v+z] = 1;
                break;
            }
        }
    }
    checkLeft(unpairs, max);
}
#endif