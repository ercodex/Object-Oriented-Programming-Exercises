#include <iostream>
using namespace std;

/*
Since obj2 is created in a local scope, it gets destroyed in the end
of scope.

On the other hand, obj1 is deleted in the end of the program.
*/

class MyClass{
public:
    MyClass(){
        cout << "Constructor: Object created." << endl;
    }

    ~MyClass(){
        cout << "Destructor: Object destroyed." << endl;
    }
};

int main(){
    MyClass obj1;  // First object is created
    {
        MyClass obj2;  // Second object is created (Local scope)
    } // obj2 is deleted here 

    return 0;  // obj1 is deleted here
}
