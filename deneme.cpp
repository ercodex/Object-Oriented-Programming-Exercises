#include <iostream>
using namespace std;

class A{
    private:
        int a;
    public:
        A(int a) : a(a) {}
        virtual ~A() = 0 {
            cout << "Destructor called." << endl;
        }
};

int main(){
    return 0;
}