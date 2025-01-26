// Reference variable is defined when we want to use a variable
// with a different name. We can reach the same variable with
// different names.

#include <iostream>
using namespace std;

int main(){

    int value = 42;
    int &ref  = value;

    cout << "Value: " << value << endl;
    cout << "Reference of Value: " << ref << endl;
    
    cout << "---------------" << endl;
    
    cout << "Address of Value: " << &value << endl;
    cout << "Address of Reference: " << &ref << endl;

    ref = 51;
    cout << "====== Reference is assigned to a difference value ======" << endl;
    cout << "Value: " << value << endl;
    cout << "Reference of Value: " << ref << endl;
    
    cout << "---------------" << endl;
    
    cout << "Address of Value: " << &value << endl;
    cout << "Address of Reference: " << &ref << endl;

    return 0;
}

// See? They're basically same variable, with different names.