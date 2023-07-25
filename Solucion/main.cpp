#include <iostream>
#include <omp.h>
#include <ctime>
#include <bits/stdc++.h>
#include "primeNumbers.cpp"
#include <list>
using namespace std;

int* primeNumbers[0];

void print(string str){
    cout << str << endl;
}

int main(int argc, char **argv){
    getPrimes(*primeNumbers, 1000);
    cout << *primeNumbers << endl;
    // for(int i = 0; i < 100; i++){
        
    // }
    return 0;
}
