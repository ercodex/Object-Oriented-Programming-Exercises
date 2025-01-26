#include <iostream>
using namespace std;

int main(){
    
    const int *ptr  = new int(10); // Data is constant, but pointer is not.
    int const *ptr2 = new int(10); // Same shit

    // *ptr = 5; This causes an error
    // ++ptr; But this is ok

    int * const ptr3 = new int(9); // Data may change, however pointer is constant
    
    // *ptr3 = 5; This is ok
    // ++ptr3; This causes an error

    const int * const ptr4 = new int(8); // Both data and pointer are constant
    int const * const ptr5 = new int(8); // Same shit

    // *ptr = 5; This causes an error
    // ++ptr; This causes an error

    delete ptr;
    delete ptr2;
    delete ptr3;
    delete ptr4;
    delete ptr5;

    return 0;
}