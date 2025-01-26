#include <iostream>
using namespace std;

/*
Classic dynamic memory allocation shit. Program is more flexible etc.
*/

class Sample {
private:
    int value;

public:

    // Constructor
    Sample(int v) : value(v) {}

    // Member function to display value
    void display() {
        cout << "Value: " << value << endl;
    }
};

int main(){

    // Dynamic memory allocation for a single object
    Sample* obj = new Sample(10);  // Create object dynamically
    obj->display();  // Accessing member function using pointer

    // Free the dynamically allocated memory
    delete obj;  // Delete object to free memory

    return 0;
}