#include <iostream>
#include <omp.h>
#include <chrono>
#include "primeNumbers.h"
#include "conjeturaFuerte.h"
using namespace std::chrono;
using namespace std;

int main(){
    // float* numerosPrimos = getPrimes(22222222);
    // for( unsigned int a = 0; a < _length; a = a + 1 ){
    // }
    int maxlimit = 100000;
    int iterator;
    auto start = high_resolution_clock::now();

    for(; iterator = getPrimes(maxlimit);){
        strong(iterator, maxlimit);
    }



    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<chrono::nanoseconds>(stop - start).count() * 1e-9;
    cout << "Time taken by program is : " << fixed
         << duration << setprecision(9);
    cout << " sec" << endl;
    return 0;
}
