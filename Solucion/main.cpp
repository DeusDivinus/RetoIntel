#include <iostream>
#include "primeNumbers.cpp"
using namespace std;



int main(){
    int* numerosPrimos = getPrimes(100);
    for( unsigned int a = 0; a < _length; a = a + 1 ){
        cout << numerosPrimos[a] << endl;
    }
    return 0;
}
