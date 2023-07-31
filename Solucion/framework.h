#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;


#ifndef framework_H
#define framework_H
class SW{
    private:
        high_resolution_clock::time_point start;
        high_resolution_clock::time_point stop;
        void stopSW(){
        stop = high_resolution_clock::now();
    };  
    public:
    void startSW(){
        start = high_resolution_clock::now();
    };  
    void showResult(){
        stopSW();
        auto duration = duration_cast<chrono::nanoseconds>(stop - start).count() * 1e-9;
        cout << "Time taken by program is : " << fixed
        << duration << setprecision(9);
        cout << " sec" << endl;
    }
};

#endif