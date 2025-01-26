#include <iostream>
using namespace std;

class Deneme{
    private:
    int sayi;
    string str;
    static int counter;

    public:

    // Constructor
    Deneme(int _sayi = 0, string _str = "empty") : sayi(_sayi), str(_str) {
        cout << "Constructor call"<< endl;
    }

    // Copy Constructor
    Deneme(const Deneme &other) : sayi(other.sayi), str(other.str) {
        cout << "Copy constructor call" << endl;
    }

    ~Deneme(){
        cout << "Destructor call" << endl;
    }

    friend ostream &operator<<(ostream &os, const Deneme &a){
        os << "isim: " << a.str << "\nyas: " << a.sayi << endl;
        return os;
    }

    Deneme &operator*=(const Deneme &a){
        sayi *= a.sayi;
        str += a.str;
        return (*this);
    }
};

int Deneme::counter = 0;

int main(){
    Deneme a(3, "eren");
    cout << a;
    Deneme b = a;
    cout << b;
    Deneme c(a);
    cout << c;
    c *= b;
    cout << c;
    return 0;
}