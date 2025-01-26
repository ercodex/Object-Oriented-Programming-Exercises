#include <iostream>
using namespace std;

/*
myArray class uses dynamic memory allocation to hold an array.
Constructor creates an array and deconstructor is called when
array is deleted from memory. By that, memory leak is prevented.
*/

class MyArray{

private:
    int* arr;
    int size;

public:
    MyArray(int s){
        size = s;
        arr = new int[size];  // Allocate memory
        cout << "Constructor: Array created." << endl;
    }

    ~MyArray(){
        delete[] arr;  // Deallocate memory
        cout << "Destructor: Array deleted." << endl;
    }
};

int main() {
    MyArray myArray(5);  // Create a dynamic array
    
    // Use myArray...
    // Use myArray...
    // Use myArray...

    return 0;  // Destructor is called and memory is deallocated
}
