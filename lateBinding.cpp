#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() { // Virtual function for late binding
        cout << "Base class display" << endl;
    }
};

class Derived : public Base {
public:
    void display() override { // Overrides base class behavior
        cout << "Derived class display" << endl;
    }
};

int main() {
    Base* obj = new Derived(); // Pointer of Base type
    /*
    Let's further analyze this writing style. What does it mean?
    What is the data type of obj? How can we decide it?

    This situation is required to enable polymorphism.

    It has two data types. Static one, and dynamic one.
    It's static data type is Base*, but it's dynamic data type is Derived class.
    This separation enables polymorphism in runtime.

    Notice that static data type is used in compile time but dynamic (late binding) data type
    is used in runtime.
    */
    obj->display();            // Late binding at runtime
    cout << "-------------" << endl;

    Base obj2;
    obj2.display();
    cout << "-------------" << endl;

    Derived obj3;
    obj3.display();
    
    delete obj;
    return 0;
}
