// There are two ways to pass some parameter to a function.
// Pass-by-value and pass-by-reference 

#include <iostream>
using namespace std;

// Select from PASS_BY_VAL or PASS_BY_REF
#define PASS_BY_VAL

#ifdef PASS_BY_VAL
int increment(int i){
    return ++i;
}
#endif

#ifdef PASS_BY_REF
int increment(int &i){
    return ++i;
}
#endif

int main(){
    
    #ifdef PASS_BY_VAL
    
    // Program allocates space in memory for variable which
    // will be used as a function parameter and sends the copy.
    // At the end, allocated space disappears. But original parameter
    // is not effected by that.

    int val = 5;
    int result;
    
    cout << "\nPASS_BY_VAL\n";
    cout << "Value: " << val << endl;
    cout << "Address of value: " << &val << endl;
    cout << "Result: " << result << endl; 
    cout << "Address of result: " << &result << endl;
    cout << "\n Incrementing... \n\n";
    result = increment(val);
    cout << "Value: " << val << endl;
    cout << "Address of value: " << &val << endl;
    cout << "Result: " << result << endl; 
    cout << "Address of result: " << &result << endl;
    #endif

    #ifdef PASS_BY_REF
    
    // We send the reference of real variable as
    // function parameter. Program doesn't allocate
    // new space for parameter variable. In function,
    // the operations made in parameter variable applies
    // to real variable.

    // Advantage is, if data is big, improves speed and
    // provides better memory allocation. 

    int val = 5;
    int result;
    
    cout << "\nPASS_BY_REF\n";
    cout << "Value: " << val << endl;
    cout << "Address of value: " << &val << endl;
    cout << "Result: " << result << endl; 
    cout << "Address of result: " << &result << endl;
    cout << "\n Incrementing... \n\n";
    result = increment(val);
    cout << "Value: " << val << endl;
    cout << "Address of value: " << &val << endl;
    cout << "Result: " << result << endl; 
    cout << "Address of result: " << &result << endl;
    #endif


    return 0;
}