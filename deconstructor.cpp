#include <iostream>
using namespace std;

/* 
This code contains information about destructor functions.
also mentions different topics such as scope, dynamic memory,
and constructor functions.
*/

/*
    Definition:
        Destructor functions are automatically called functions when an object
        is destroyed (i.e. when it is no longer in use or deleted with 'delete' keyword
        from memory). It has the same name with classes name, but with a '~' (tilda) sign
        in front. 
    Use Case:
        They're used to deallocate dynamically allocated memory. They're also used for
        cleaning other stuff too.
*/

class myClass{
    public:

        myClass(){
            cout << "class is created." << endl;
        }

        ~myClass(){
            cout << "class is destroyed." << endl;
        }
};

int main(){
    myClass obj; // Constructor function is called here.
    
    // use obj...
    // use obj...
    // use obj...
    
    return 0; // Destructor function is called here automatically.
}

/*

Generally, destructors are needed to release sources in a correct way.

A destructor is as important as a constructor. It plays a critic role
in memory management and source cleaning.

In a destructor, we should only perform tasks with limited-access to resources
in order to release memory safely.

If we don't declare a destructor as a programmer, C++ does it itself.
It creates a default destructor to get the job done. It makes sure
there are no unnecessary stuff left behind. But if there are more than
basic C++ data types, we may have to do it manually. Consider doing it
when code gets complicated.

Generally, there is no need to declare a destructor when there is no 
dynamic memory allocation. Also there is no need for a destructor when
there are STL containers (vector, string) or smart pointers. Both have 
their own destructors.

Example case when there is a need for a destructor is, file operations.
We need to close if we opened a file before. Another use case is when
we perform web tasks. 
*/