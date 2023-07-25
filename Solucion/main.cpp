#include <iostream>
#include <omp.h>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

void print(string str){
    cout << str << endl;
}

void getPrimes(int n){
    for(int i = 0; i < n; i++)
    {
        string boolresult = isPrime(i) ? "Primo" : "Normal";
        string out = to_string(i)+" es "+boolresult;
        print(out);
    }
}

int main(int argc, char **argv){
    getPrimes(1000);
    // for(int i = 0; i < 100; i++){
        
    // }
    return 0;
}
