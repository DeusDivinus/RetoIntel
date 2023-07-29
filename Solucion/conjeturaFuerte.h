#include <iostream>
#include <omp.h>
#include <list>
#include "primeNumbers.h"
using namespace std;
 
vector<int> pairs;
vector<int> getResult(vector<int> primes, int number, int max, int newAt = 0)
{
    if (number > max){
        cout << primes.at(newAt) << endl;
        return pairs;
    }
    for(int v: primes){
        if(v < primes.at(newAt))
        {
            continue;
        }

        if(number % 7 == 0 && number % 3 == 0)
        {
            if(primes.at(newAt) < number/2)
            {
                newAt += 3;
            }
            newAt += 2;
        }

        for(int x: primes)
        {
            if(x > number)
            {
                break;   
            }
            int result = v+x;
            if(result == number){;
                pairs.push_back(result);
                return getResult(primes, number+2, max, newAt);
            }
        }
    }
    return pairs;
}

void strong(vector<int> primes, int min, int max)
{
    getResult(primes, 4, max);
    // list<int> pairs(max);
    // for(int v: primes){
        // for(int x: primes)
        // {
            // int result = v+x;
            // if(result % 2 == 0 && result <= max){;
                // pairs.insert(pairs.begin()+result, 1, result);
            // }
        // }
        // cout << v << endl;
    // }
    cout << pairs.size() << endl;
    sort(pairs.begin(), pairs.end());
    for(auto x : pairs)
        cout << x << endl;
}