// Operator and Function Overloading

#include <iostream>
using namespace std;

struct Complex {
    double imag;
    double real;

    // Constructor to initialize real and imaginary parts.
    Complex(double i = 0.0, double r = 0.0) : imag(i), real(r) {}
};

Complex operator+ (const Complex &a, const Complex &b){
    Complex sum;
    sum.real = a.real + b.real;
    sum.imag = a.imag + b.imag;
    return sum;
}

Complex operator* (const Complex &a, const Complex &b){
    Complex product;
    product.imag = (a.imag * b.real) + (b.imag * a.real);
    product.real = -(a.imag * b.imag) + (a.real * b.real);
    return product;
}

// Here, we overload << operator.
ostream& operator<<(ostream& os, const Complex& c){
        os  << c.imag << "i + " << c.real << endl;
        return os;
    }

int main(){
    
    // Defining two complex numbers
    Complex num1(4, 7);  //  4i + 7
    Complex num2(-2, 1); // -2i + 1
    
/*  We can't just add like this. We need to overload.

    cout << num1 + num2;

    Because, C++ doesn't have to know about how to add 
    and print them. This is our unique data type. So, its
    our responsibility to define operations for it (e.g. +, -, *, /). 
    And this is called "operator overloading".
*/
//=======================================================================================

    Complex sum = num1 + num2;
/*  cout << sum;
    Ok. They're summed up. But still can't print. Because, "<<, >>"
    these are also operators! C++ still don't know HOW to print them.
*/  
    // This totally works but, we can improve it by directly overloading '<<' operator
    cout << "Sum: " << sum.imag << "i + " << sum.real << endl;
    // We overloaded in line 23.
    
    // This role of '<<' only works when user wants to print complex numbers. 
    cout << "Sum with overloading: " << sum << endl;

//=======================================================================================
    
    // Here is the product of num1 and num2.
    Complex product = num1 * num2;
    cout << "Product: " << product << endl;
    return 0;
}