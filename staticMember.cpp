#include <iostream>
using namespace std;

/*

A static member is shared among all objects (instances) of a class.
It means this static member is reached directly by class itself, not
class's objects. They all share this same static member.

In this particular example, there is a static member called count.
It is aimed to increment it when there is a new instance created from
Counter class.

Static members are useful when there is need to hold an information which 
is shared among objects. It enables us to hold data in 'class' manner. 

*/

class Counter {
private:
    static int count;  // Static member to keep track of count

public:
    Counter() {
        count++;  // Increment count for each new object
    }

    static int getCount() {
        return count;  // Returns the current count
    }
};

// Initialize the static member
int Counter::count = 0;

int main() {
    Counter c1;  // Creates first object
    Counter c2;  // Creates second object

    cout << "Number of objects created: " << Counter::getCount() << endl;  // Access static member
}

/*

Isn't it interesting that we can access private static members from outside?
It is because that since they don't belong to any instance of the class, they
are accessible directly by the name of the class.

Static member initialization: It is made outside the declaration of class
and only made once. It allocates space from memory and all objects share this
value.

Static function access: getCount() is a static function. It can be called without
an object and has access to private static members of the class.
When we call it like 'Counter::getCount()', it returns the current value of variable
'count'.

*/