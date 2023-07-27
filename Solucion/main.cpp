#include <iostream>
#include <fstream>
#include <omp.h>
#include <chrono>
#include "primeNumbers.h"
#include "conjeturaFuerte.h"

using namespace std::chrono;
using namespace std;

int iterator; // Used in main()
int iterationMilestones = 1; // Used in main()

int maxlimit = 2200000; // Limit range (0-{maxlimit})
int main(){
    // float* numerosPrimos = getPrimes(22222222);
    // for( unsigned int a = 0; a < _length; a = a + 1 ){
    // }
    auto start = high_resolution_clock::now();
    auto startMilestone = high_resolution_clock::now();
    ofstream myf;
    string mystr = "e";
    myf.open("test.txt");
    cout << mystr << endl;
    myf.close();
    
    // for(; iterator = getPrimes(maxlimit);){
    //     if (iterationMilestones <= iterator*10)
    //     {
    //         cout << iterationMilestones << endl;
    //         iterationMilestones *= 10;
    //         auto stopMilestone = high_resolution_clock::now();
    //         auto durationMilestone = duration_cast<chrono::nanoseconds>(stopMilestone - startMilestone).count() * 1e-9;
    //         cout << "Time taken to milestone : " << fixed
    //         << durationMilestone << setprecision(9);
    //         cout << " sec" << endl;
    //         startMilestone = high_resolution_clock::now();
    //     }
    // }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<chrono::nanoseconds>(stop - start).count() * 1e-9;
    cout << "Time taken by program is : " << fixed
         << duration << setprecision(9);
    cout << " sec" << endl;
    return 0;
}
