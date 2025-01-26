#include <iostream>
#include <cstring>
using namespace std;

/*
Copy constructor is called when an pbject is created as a 
copy of another object. It is usually defined as follows:

ClassName(const ClassName& other);

Warning: If a class uses dynamic memory, it is essential to manage
resources correctly using the copy constructor.

*/

class Sample {
private:
    char* name;

public:
    // Constructor
    Sample(const char* n){
        cout << "Constructor called." << endl;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Copy Constructor
    Sample(const Sample& other){
        cout << "Copy constructor called." << endl;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    // Destructor
    ~Sample(){
        cout << "Destructor called." << endl;
        delete[] name;
    }

    // Display function
    void display(){
        std::cout << "Name: " << name << std::endl;
    }
};

int main(){
    Sample obj1("Eren");
    Sample obj2 = obj1;  // Calls Copy Constructor

    obj1.display();
    obj2.display();

    return 0;
}
