#include <iostream>
#include "primeNumbers.h"
#include "conjeturaFuerte.h"
using namespace std;



int main(){
    // float* numerosPrimos = getPrimes(22222222);
    // for( unsigned int a = 0; a < _length; a = a + 1 ){
    // }
    int maxlimit = 22222222;
    int iterator;
    for(; iterator = getPrimes(maxlimit);){
        cout << iterator << endl;
        strong(iterator, maxlimit);
    }
    return 0;
}
