#include <iostream>
#include <fstream>
#include <omp.h>
#include <bits/stdc++.h>
#include <pthread.h>
#include <chrono>
#include <vector>
#include "primeNumbers.h"
#include "conjeturaDebil.h"
#include "conjeturaFuerte.h"
#include "framework.h"
using namespace std::chrono;
using namespace std;

// ofstream MyFile("filename.txt");
// MyFile.close();
int minLimit = 0;
int maxLimit = 22000000;
int strongLimit = 22000000;
int weakLimit = 111111;

SW mainSW;
SW xSW;

int main(){
    ofstream MyFile("primes.txt");
    vector<char> primes;
    mainSW.startSW(); primes = getPrimes(0, maxLimit)   ; mainSW.showResult();
    cout << "Finished search\n" << "Size:" << primes.size() << endl;
    #pragma omp parallel
    {
        #pragma omp single
        {
            mainSW.startSW(); strong(primes, minLimit, strongLimit); mainSW.showResult();
        }
    }
    #pragma omp parallel
    {
        #pragma omp single
            {
                mainSW.startSW(); weak(primes, minLimit, weakLimit); mainSW.showResult();
            }
    }
    MyFile.close();
    return 0;
}
