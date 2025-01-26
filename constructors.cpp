/* 
This code provides information about constructor functions
in object-oriented programming. Also offers different syntaxes.
*/

#include <iostream>
using namespace std;

// Complex number class
class Complex{ 

    public:

        // Complex number member data
        // They are in public for simplicity sake
        double imag;
        double real;

        /* Constructor function
        
        This function contains default parameters. 
            If user doesn't provides arguments, they have their own default values.
            Check 'defaultParameters.cpp' for more info.

        The part after ':' is called an 'initializer list'.
            When constructor is called, it is used to initialize class's member variables.
            It is recommended to use it in terms of efficiency. With the help of initializer 
            list, member variables are initialized before entering the constructor body ( {} ).

        In human language: 
            variable 'imag' from 'Complex' class is initialized with 'i' parameter
            variable 'real' from 'Complex' class is initialized with 'r' parameter

        As you can see, constructor body is empty because member variables are already 
            initialized with an initializer list. 
        
        Why do we use constructor function like this?
            Because initializing member variables (especially 'const' or '&' typed ones) like this is more
            efficient, fast, and safe. Why is it? Because instead of assigning directly, they're initialized 
            directly. And this prevents unnecessary copying in large-scale classes. As a second benefit, default 
            parameters enables the function to work even there is no arguments given by user. And this leads to 
            more flexible code.
        */
        Complex(double i = 0.0, double r = 0.0) : imag(i), real(r) {}

};

/*
There are other syntaxes too.
But they're not promised to increase efficiency.

1)
class Complex {
    public:
        double imag, real;

        Complex(double i = 0.0, double r = 0.0) {
            imag = i;  
            real = r;  
        }
};

2)
class Complex {
public:
    double imag, real;

    Complex(double i = 0.0) : imag(i), real(0.0) {}
};


*/

int main(){

    Complex num1;
    num1.real = 3;
    num1.imag = 5;

    cout << num1.real << "i" << " + " << num1.imag  << endl;
    return 0;
}