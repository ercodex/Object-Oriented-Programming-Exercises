#include <iostream>
#include <string>
using namespace std;

class Base{
public:
    virtual int f() const {
        cout << "Base::f()" << endl;
        return 1;
    }
    virtual void f(string) const {}
    virtual void g() const {}
};

class Derived1 : public Base{
public:
    void g() const {}
};

class Derived2 : public Base{
public:
    // Overriding a virtual function
    int f() const {
        cout << "Derived2::f()" << endl;
        return 2;
    }
};

class Derived3 : public Base{
public:
    // Cannot change return type:
    // void f() const {
    //     cout << "Derived3::f()" << endl;
    // } 
};

class Derived4 : public Base {
public:
    // Change argument list:
    int f(int) const {
        cout << "Derived4::f()" << endl;
        return 4;
    }
};

int main(){
    return 0;
}