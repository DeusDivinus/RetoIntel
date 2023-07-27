#include <iostream>
#include <omp.h>
#include "primeNumbers.h"
using namespace std;
 
void getResult(int prime, int number)
{
    if(isPrime(number-prime))
    {
        
    }
}

void strong(int prime, int limit)
{
    for(; int i = getPrimes(limit);){
        getResult(prime, i);
    }
}


// int main(){
//     for(int i = 0; i <= 22222222; i++){
//         if(i == 22222222){
//             cout << "22222222" << endl;
//         };
//     }
//     cout << "ready" << endl;
//     return 0;
// }