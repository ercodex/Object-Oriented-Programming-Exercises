#include <iostream>
#include <cstring>

/*
The Rule of Three is a fundamental guideline in C++ that states if a class manages 
resources such as dynamic memory, file handles, or network connections, it should 
explicitly define three special member functions:

    Destructor: Cleans up resources when an object is destroyed.
    Copy Constructor: Initializes a new object as a copy of an existing object.
    Copy Assignment Operator: Assigns the values from one object to another of the same class.

If a class requires any of these three functions, it is likely that it needs all three 
to manage resources correctly and avoid resource leaks or double deletions.

*/

class Sample {
private:
    char* data; // Dynamic memory resource

public:
    // Constructor
    Sample(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy Constructor
    Sample(const Sample& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy Assignment Operator
    Sample& operator=(const Sample& other) {
        if (this != &other) { // Self-assignment check
            delete[] data; // Free existing resource
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Destructor
    ~Sample() {
        delete[] data; // Clean up dynamic memory
    }

    // Display function
    void display() const {
        std::cout << "Data: " << data << std::endl;
    }
};

int main() {
    Sample obj1("Hello, World!");
    Sample obj2 = obj1; // Calls Copy Constructor
    Sample obj3("Initial");

    obj3 = obj1; // Calls Copy Assignment Operator

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}

/*

Memory Management: By implementing these three functions, you ensure that 
your class properly manages dynamic memory, preventing leaks or undefined behavior.

Resource Integrity: Properly defined copy operations ensure that each instance of 
the class maintains its own copy of the resource, preventing issues related to shared ownership.

*/