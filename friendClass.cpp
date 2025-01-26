#include <iostream>
using namespace std;

/*
Friend classes in C++ are classes that are given access to the private and protected members of 
another class. This relationship can be useful when two or more classes need to cooperate closely 
while still keeping their data encapsulated.

Why Use Friend Classes?

Access Control: It allows one class to access the private data of another class without exposing that data to the entire world.

Encapsulation: You can keep your data hidden from other classes but still provide controlled access to specific classes that need it.

Simplified Interfaces: It allows for cleaner and more straightforward interfaces between closely related classes.

*/

class B; // Forward declaration

class A{
private:
    int valueA;

public:
    A(int val) : valueA(val) {}

    // Declare B as a friend class
    friend class B;
};

class B{
public:
    void showA(const A& a) {
        cout << "Value of A: " << a.valueA << endl; // Accessing private member of A
    }
};

int main(){
    A a(42);
    B b;
    b.showA(a); // B can access the private member of A

    return 0;
}

/*
Class Declaration:
    class B; is a forward declaration of class B, which allows A to recognize B without needing its 
    full definition at that point.

Friendship Declaration:
    friend class B; inside class A grants class B access to all private and protected members of class A.

Accessing Private Members:
    Inside the showA method of class B, we can access the private member valueA of class A because 
    class B is a friend of class A.

Tight Coupling: 
    Using friend classes can create tight coupling between classes, which can lead to code 
    that is harder to maintain. Use this feature judiciously.

Encapsulation Break: 
    Friend classes break encapsulation principles to some extent. Consider whether this level of 
    access is truly necessary.
*/