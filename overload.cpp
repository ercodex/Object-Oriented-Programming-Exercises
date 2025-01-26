// Operator and Function Overloading
#include <iostream>
using namespace std;

//===============================
#define MISSION_5 // SELECT MISSION
//===============================

#ifdef MISSION_1

// Here, we overload << operator.

struct Complex {
    double imag;
    double real;

    // Constructor to initialize real and imaginary parts.
    Complex(double i = 0.0, double r = 0.0) : imag(i), real(r) {}
};


Complex operator+ (const Complex &a, const Complex &b){
    Complex sum;
    sum.real = a.real + b.real;
    sum.imag = a.imag + b.imag;
    return sum;
}

ostream& operator<<(ostream& os, const Complex& c){
    os  << c.imag << "i + " << c.real << endl;
    return os;
}
#endif // MISSION_1 END

#ifdef MISSION_2

struct Vector3D{
    float X;
    float Y;
    float Z;

    // Initializer
    Vector3D(float x = 0.0, float y = 0.0, float z = 0.0) : X(x), Y(y), Z(z) {}
};

Vector3D operator* (const Vector3D &vector, float scalar){
    Vector3D product;
    product.X = vector.X * scalar;
    product.Y = vector.Y * scalar;
    product.Z = vector.Z * scalar;
    return product;
}

ostream& operator<<(ostream& os, const Vector3D &product){
    os  << "(" << product.X << ", " << product.Y << ", " << product.Z << ")" << endl;
    return os;
}
#endif // MISSION_2 END

#ifdef MISSION_3

struct Fraction{
    float num;
    float denum;

    // Initializer
    Fraction(float n = 0.0, float d = 0.0) : num(n), denum(d) {}
};

bool operator==(const Fraction &a, const Fraction &b){ // Type is bool because it returns bool values.
    if( (a.num / a.denum) == (b.num / b.denum) ){
        return 1;
    }
    else{
        return 0;
    }
}

ostream& operator<<(ostream& os, const Fraction &product){
    os  << product.num << "/" << product.denum;
    return os;
}

#endif // MISSION_3 END

#ifdef MISSION_4

// Integer data type version of max()
int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

// Double data type version of max()
double max(double a, double b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

// Char data type version of max()
char max(char a, char b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

#endif // MISSION_4 END

#ifdef MISSION_5

void print(int a){
    cout << a << endl;
}

void print(double b){
    cout << b << endl;
}

void print(string c){
    cout << c << endl;
}
void print(char d){
    cout << d << endl;
}
#endif // MISSION_5 END

int main(){

    #ifdef MISSION_1
    
    Complex num1(4, 7);  //  4i + 7
    Complex num2(-2, 1); // -2i + 1
    
    Complex sum = num1 + num2; 
    cout << "Sum: " << sum;
    
    #endif // MISSION_1 END

    #ifdef MISSION_2

    Vector3D vec1(2, -3, 1); 
    float scalar = -1.7;
    Vector3D product = vec1 * scalar;
    cout << "Product: " << product << endl;

    #endif // MISSION_2 END

    #ifdef MISSION_3
    
    Fraction num1(3, 5);  // 3/5
    Fraction num2(6, 10); // 6/10
    Fraction num3(3, 4);  // 3/4

    if(num1 == num2){
        cout << num1 << " is equal to " << num2 << endl;
    }
    else{
        cout << num1 << " is not equal to " << num2 << endl;
    }

    if(num2 == num3){
        cout << num2 << " is equal to " << num3 << endl;
    }
    else{
        cout << num2 << " is not equal to " << num3 << endl;
    }

    #endif // MISSION_3 END

    #ifdef MISSION_4
    
    int a = 5;
    int b = 2;

    double c = 1.6;
    double d = 9.2;

    char e = 'K';
    char f = 'm';

    cout << "Big one from " << a << " and " << b << " is: " << max(a, b) << endl;
    cout << "Big one from " << c << " and " << d << " is: " << max(c, d) << endl;
    cout << "Big one from " << e << " and " << f << " is: " << max(e, f) << endl;
    
    #endif // MISSION_4 END

    #ifdef MISSION_5
    
    int a = 42;
    double b = 6.3;
    string c = "foo";
    char d = 'n';

    print(a);
    print(b);
    print(c);
    print(d);

    #endif // MISSION_5 END
    
    return 0;
}