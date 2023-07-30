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
int minLimit = 0;
int maxLimit = 22222222;
SW mainSW;
SW xSW;

int main(){
    mainSW.startSW();
    ofstream MyFile("primes.txt");
    vector<bool> primes;
    primes = getPrimes(0, maxLimit);
    strong(primes, minLimit, maxLimit);

    cout << "Finished search\n" << "Size:" << primes.size() << endl;
    MyFile.close();
    mainSW.showResult();
    return 0;
}
