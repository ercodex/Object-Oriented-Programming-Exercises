// A function template can take a class as a parameter

#include <iostream>
#include <string>
using namespace std;

class A{
private:
    int a;

public:
    A(int q = 0){
        a = q;
    }

    bool operator==(const A &right) const {
        if(a == right.a)
            return true;
        else{
            return false;
        }
    }
};

template <typename T>
bool compare(const T &x, const T &y){
    return x == y;
}

int main(){
    A objA(1), objB(2);
    int a = 2, b = 2;

    compare(objA, objB);
    compare(a,b);
    
    return 0;
}

