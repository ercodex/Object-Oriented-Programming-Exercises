#include <iostream>
using namespace std;

/*
When they're defined, they cannot be changed. They're used
to reduce the likelihood of getting errors.

Const data members can be initialized only in constructor. 
*/

class Sample{
public:
    int value;

    Sample(int v) : value(v) {}
};

int main(){
    const Sample obj(10);  // Const object
    // obj.value = 20;     // Error: cannot modify a const object
    cout << "Value: " << obj.value << endl;

    return 0;
}
