#include <iostream>
#include <string>
using namespace std;

double divide(int a, int b){
    if(b==0) throw "divide by zero";
    return ((double)a/b);
}

int main(){
    int x = 5;
    int y = 0;
    
    double result;
    try{
        result = divide(x, y);
    }
    catch(string s){
        cout << s << endl;
    }
    return 0;
}