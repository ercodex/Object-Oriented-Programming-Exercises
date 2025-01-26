#include <iostream>
using namespace std;

class Vector{
    private:
    int x;
    int y;
    int z;

    public:
    // Constructor
    Vector(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {
        cout << "Constructor call" << endl;
    }

    // Copy Constructor
    Vector(const Vector &other) : x(other.x), y(other.y), z(other.z) {
        cout << "Copy Constructor call" << endl;
    }

    // Copy assignment operator
    Vector operator=(const Vector &other){
        cout << "Copy Assignment call" << endl;
        if(this != &other){
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    // Destructor
    ~Vector(){
        cout << "Destructor call" << endl;
    }

    // Add operator overloaded inside the class
    Vector operator+(const Vector &v) const {
        return Vector(x+v.x, y+v.y, z+v.z);
    }

    // Defined outside the class
    friend Vector operator-(const Vector &L, const Vector &R);

    // *= Operator overloaded inside the class
    Vector operator*=(const Vector &v){
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    // Comparing operators defined outside class
    // If it wasn't a friend and just defined
    // under the class, we wouldn't need two parameters.
    friend bool operator<(const Vector &L, const Vector &R);

    bool operator>(const Vector &v) const {
        if(x*y*z > v.x * v.y * v.z){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator==(const Vector &v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    // Since we defined the == operator, we can
    // use it!
    bool operator!=(const Vector &v) const {
        return !(*this == v);
    }
    
    friend ostream &operator<<(ostream& os, const Vector &v){
        os << "Vector: (" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
        return os;
    }

    // Increment operator
    Vector &operator++(){
        ++x;
        ++y;
        ++z;
        return *this;
    }
    
    Vector &operator--(){
        --x;
        --y;
        --z;
        return *this;
    }

    Vector &operator++(int){
        Vector temp = *this;
        ++x;
        ++y;
        ++z;
        return temp;
    }
};

// Subtraction operator overloaded outside the class
Vector operator-(const Vector &L, const Vector &R) {
    return Vector(L.x - R.x, L.y - R.y, L.z - R.z);
}

bool operator<(const Vector &L, const Vector &R){
    if(L.x * L.y * L.z < R.x * R.y * R.z){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    
    Vector n(1, 3, 5);
    cout << "n: " << n << endl;
    
    Vector m(5, 7, 8);
    cout << "m: " << m << endl;
    
    Vector x = n + m;
    cout << "x: " << x << endl;

    n *= x;
    cout << "n: " << n << endl;

    Vector y(6, 30, 65);
    
    if(y == n){
        cout << "y equals n" << endl;
    }
    cout << m++;
    cout << ++m;
    
    return 0;
}