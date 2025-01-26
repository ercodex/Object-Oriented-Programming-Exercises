#include <iostream>
using namespace std;

template <typename T>
T abs_template(T a){
    if(a < 0){
        return -a;
    }
    else{
        return a;
    }
}

int main(){
    int a = -5;
    float b = -4.2;
    double c = -3.645211;

    cout << abs_template(a) << endl;
    cout << abs_template(b) << endl;
    cout << abs_template(c) << endl;

    return 0;
}