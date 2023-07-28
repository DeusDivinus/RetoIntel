#include <iostream>
#include <fstream>
#include <omp.h>
#include <pthread.h>
#include <chrono>
#include <vector>
#include "primeNumbers.h"
#include "conjeturaFuerte.h"

using namespace std::chrono;
using namespace std;

class SW{
    private:
        high_resolution_clock::time_point start;
        high_resolution_clock::time_point stop;
    public:
    void startSW(){
        start = high_resolution_clock::now();
    };
    void stopSW(){
        stop = high_resolution_clock::now();
    };    
    void showResult(){
        stopSW();
        auto duration = duration_cast<chrono::nanoseconds>(stop - start).count() * 1e-9;
        cout << "Time taken by program is : " << fixed
        << duration << setprecision(9);
        cout << " sec" << endl;
    }
};

// ofstream MyFile("filename.txt");
// MyFile.close();
int maxLimit = 222222 ;
SW newSW;
int main(){
    newSW.startSW();
    ofstream MyFile("primes.txt");
    vector<int> primes;
    int lastPrime = 2;
    for(; int i = getPrimes(0, maxLimit);)
    {
        primes.insert(primes.begin()+primes.size(), 1, i);
        // if(lastPrime && (lastPrime + i) % 2 == 0){
        //     cout << lastPrime+i << '='
        //     << lastPrime << '+'
        //     << i << endl;
        // }
        lastPrime = i;
    }

    MyFile.close();
    newSW.showResult();
    return 0;
}
