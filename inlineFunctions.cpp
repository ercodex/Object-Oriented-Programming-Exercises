// In C, macros are defined with #define
// In C++, we can define functions with 'inline' keyword as macros.

#include <iostream>
using namespace std;

inline double cube (const double side){
    return side*side*side;
}

int main(){
    
    double sideValue = 2; // First integer to add
    
    cout << "Volume of the cube with the side length of" << sideValue 
    << " is " << cube(sideValue) << endl;

    return 0;
}

// Compiler copies the function(!) codes when it is called.
// There is no function call.
// Program works faster however its size goes higher.