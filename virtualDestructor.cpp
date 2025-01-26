// This code demonstrates the usage of "virtual" keyword in destructors. 

#include <iostream>
using namespace std;

class Base {
public:
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor" << endl; }
};

int main() {
    Base* obj = new Derived();
    delete obj; // Sadece Base::~Base() çağrılır, Derived::~Derived() çağrılmaz!
    return 0;
}

/*
class Base {
public:
    virtual ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor" << endl; }
};

int main() {
    Base* obj = new Derived();
    delete obj; // Hem Derived::~Derived() hem de Base::~Base() çağrılır.
    return 0;
}

*/