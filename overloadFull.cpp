#include <iostream>
using namespace std;

class Human{
    private:
    string name;
    int age;

    public:

    // Constructor
    Human(string _name, int _age) : name(_name), age(_age){
        cout << "Constructor call" << endl;
    }

    // Copy Constructor
    Human(const Human &other) : name(other.name), age(other.age){
        cout << "Copy constructor call" << endl;
    }

    // Copy Assignment Operator
    Human &operator=(const Human &other){
        cout << "Copy assignment operator call" << endl;
            if(this != &other){ // Self-assignment check
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    // Destructor
    ~Human(){
        cout << "Destructor call" << endl;
    }

    friend ostream& operator<<(ostream& os, const Human &a){
        os << "Name: " << a.name << "\nAge: " << a.age << endl;
        return os;
    }

    
};

int main(){
    Human eren("eren", 20);
    cout << eren << endl;
    
    Human erdem("erdem", 16);
    cout << erdem << endl;

    Human hamza("hamza", 8);
    cout << hamza << endl;
    
    Human test(eren);
    cout << test << endl;
    
    Human test2 = erdem;
    cout << test2 << endl;

    Human test3(hamza);
    cout << test3 << endl;

    Human mete("mete", 20);
    mete = erdem;
    cout << mete << endl;

    return 0;
}