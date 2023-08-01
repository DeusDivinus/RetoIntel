#include <iostream>
#include <omp.h>
#include <pthread.h>
#include <chrono>
#include <vector>
#include "framework.h"
using namespace std::chrono;
using namespace std;

// ofstream MyFile("filename.txt");
// MyFile.close();
int minLimit = 0;
int maxLimit = 2222222;
int strongLimit = 2222222;
int weakLimit = 10000;

vector<char> primes;

SW mainSW;

int main(){
    // ofstream MyFile("primes.txt");
    // MyFile.close();

    mainSW.startSW(); primes = getPrimeNumbers(0, maxLimit); mainSW.showResult();
    cout << "Finished search\n" << "Size:" << primes.size() << endl;
    #pragma omp parallel
    {
        #pragma omp single
        {
            mainSW.startSW(); strongConjecture(primes, minLimit, strongLimit); mainSW.showResult();
        }
    }
    #pragma omp parallel
    {
        #pragma omp single
            {
                mainSW.startSW(); weakConjecture(primes, minLimit, weakLimit); mainSW.showResult();
            }
    }

    return 0;
}
