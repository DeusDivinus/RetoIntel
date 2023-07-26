#include <iostream>
#include "primeNumbers.h"
using namespace std;
 
void getResult(int number, int prime)
{
    if(isPrime(number-prime))
    {
        cout << number;
        cout << "=";
        cout << prime;
        cout << "+";
        cout << number-prime << endl;
    }
}

void strong(int prime, int limit)
{
    for(int i = 0; i <= limit; i++){
        if(prime<i && i%2==0){
            getResult(i, prime);
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