#include <iostream>
using namespace std;

void print(int i = 1, int j = 2); // Two parameters with default values.

int main(){

    print(5, 10); // Two real parameter function call
    print(5);     // One real parameter function call
    print();      // Function call without real parameter
 
    return 0;
}

void print(int i, int j){
    cout << i << " " << j << endl;
}

// In function parameters, default values 
// must be at right most. If exists. 

// void print(int i = 0, int j); ---> Not-Valid
// void print(int i, int j = 2); ---> Valid

// Default values must be given in declaration phase.
// It is not possible to give it in both  
// declaration and definition at the same time.
// If user gives default values in both dec. and def.
// It will raise an error.

// void print(int i, int j = 2); ---> Declaration, valid.

/*

void print(int i, int j = 2){ ---> Declaration and Definition, valid.
    .
    .
    .                              
}

*/