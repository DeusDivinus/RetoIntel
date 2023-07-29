#include <iostream>
#include <fstream>
#include <omp.h>
#include <bits/stdc++.h>
#include <pthread.h>
#include <chrono>
#include <vector>
#include "primeNumbers.h"
#include "conjeturaFuerte.h"
#include "framework.h"
using namespace std::chrono;
using namespace std;

// ofstream MyFile("filename.txt");
// MyFile.close();
int maxLimit = 100000;
SW mainSW;
SW xSW;

int main(){
    mainSW.startSW();
    ofstream MyFile("primes.txt");
    vector<int> primes;
    // for(; int i = getPrimes(0, maxLimit);)
    // {
    //     primes.insert(primes.begin()+primes.size(), 1, i);
    // }
    int i;
    for(i = 0; i <= maxLimit; i++){
        if(isPrime(i)){
            primes.insert(primes.begin()+primes.size(), 1, i);
        }
    }
    strong(primes, 0, maxLimit);

    cout << "Finished search\n" << "Size:" << primes.size() << endl;
    MyFile.close();
    mainSW.showResult();
    return 0;
}
