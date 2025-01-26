/*
1) Static Binding (Non-Virtual Functions):
When a function is not marked as virtual, the type of the reference or pointer determines 
which version of the function is called. The actual type of the object is ignored.

2) Dynamic Binding (Virtual Functions):
When a function is marked as virtual, the actual type of the object determines which version
 of the function is called, even if accessed through a base class reference or pointer.

3)The Importance of virtual:
Without virtual, polymorphism does not occur. This is why f1 always 
calls Base::f1, regardless of whether the object is actually of type Derived.
*/

#include <iostream>

class Base {
public:
    void f1() { std::cout << "Base::f1" << std::endl; }
    virtual void f2() { std::cout << "Base::f2" << std::endl; }
};

class Derived : public Base {
public:
    void f1() { std::cout << "Derived::f1" << std::endl; }

    //Being virtual tells the compiler to use dynamic binding for this function.
    void f2() override { std::cout << "Derived::f2" << std::endl; }
};

int main() {
    Derived d;
    Base& b = d; // Upcasting

    b.f1(); // Output is Base::f1
    b.f2(); // Output is Derived::f2

    // It doesn't matter what you defined. If you didn't put virtual there, it still
    // going to use Base class.

    return 0;
}
