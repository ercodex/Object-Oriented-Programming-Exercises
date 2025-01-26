#include <iostream>
using namespace std;

class Base{ // Base
protected:
    int member;
public:
    Base(){
        cout << "Base Constructor" << endl;
    }
    ~Base(){
        cout << "Base Destructor" << endl;
    }
};

// Make ---> class Base1 : virtual public Base
class Base1 : public Base{ // Derived from Base
public:
    Base1(){
        cout << "Base1 Constructor" << endl;
    }
    ~Base1(){
        cout << "Base1 Destructor" << endl;
    }
};

// Make ---> class Base2 : virtual public Base
class Base2 : public Base{ // Derived from Base
public:
    Base2(){
        cout << "Base2 Constructor" << endl;
    }
    ~Base2(){
        cout << "Base2 Destructor" << endl;
    }
};

class Derived : public Base1, public Base2{
public:
    void f(){                       // This creates ambiguity.
        member++;                   // Because Derived class contains "member" two times.  
    }                               // To solve this, use "virtual" keyword.
                                    // It tells the compiler that just inherit one member.
}



int main(){
    return 0;
}