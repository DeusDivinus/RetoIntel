#include <iostream>
#include <omp.h>
#include <pthread.h>
#include <chrono>
#include <vector>
#include "framework.h"
using namespace std::chrono;
using namespace std;

// ofstream MyFile("filename.txt");
// MyFile.close();
int minLimit;
int maxLimit;

int strongLimit;
int weakLimit;

SW mainSW;

// * input: Get the int input of user
// ?     | inputMsg: string telling the user what to input
// ?     | limit: limit of the input
int input(string inputMsg, int limit = 0){
    double newInput = 0;
    cout << inputMsg << ": ";
    cin >> newInput;
    if(newInput >= limit & limit != 0)
    {
        cout << "Limite excedido (" << limit << "), intente de nuevo" << endl;
        return input(inputMsg, limit);
    }
    return newInput;
}

int main(){
    // ! Clean up files for re-execution
    ofstream pairsFile("primePairs.txt", std::ofstream::out | std::ofstream::trunc);
    ofstream unpairsFile("primeUnpairs.txt", std::ofstream::out | std::ofstream::trunc);
    pairsFile.close();
    unpairsFile.close();

    // * Data input (range of numbers)
    cout << "Busqueda de numeros (Conjetura de Goldbach)" << endl;
    minLimit =    input("Ingrese el numero minimo a usar en la busqueda");
    strongLimit = input("Ingrese el limite para la busqueda de pares (Max: 22,222,222)", 22222222);
    weakLimit =   input("Ingrese el limite para la busqueda de impares (Max: 111,111)", 111111);
    maxLimit = strongLimit > weakLimit ? strongLimit : weakLimit;
    vector<char> primes = getPrimes(minLimit, maxLimit);

    // * get all prime pairs
    mainSW.startSW(); 
    strongConjecture(primes, minLimit, strongLimit); 
    cout << "Finished pairs search" << endl;

    // * get prime unpairs
    weakConjecture(primes, minLimit, weakLimit);
    cout << "Finished unpairs search" << endl;
    mainSW.showResult();

    return 0;
}
