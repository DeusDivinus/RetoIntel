#include <iostream>
#include <omp.h>
#include "primeNumbers.h"
using namespace std;
 
void getResult(int number, int prime)
{
    if(isPrime(number-prime))
    {
        
    }
}

void strong(int prime, int limit)
{
    #pragma opm parallel
    {
    for(int i = 2, by = 0; i < limit/2; i++, by += 2){
    }
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