// Upcasting is the process of treating an object of a derived class as if it were an 
// object of its base class. This happens naturally in object-oriented programming 
// and is common in polymorphism.

// It allows for generalization: you can write code that works with the base class and 
// automatically applies to all derived classes. It is essential for enabling polymorphism, 
// where the correct method of the derived class is executed even when accessed through 
// a base class pointer or reference.

// When you assign a derived class object to a base class reference or pointer, an 
// upcast occurs. This is safe because every derived class object is-a base class object.

#include <iostream>
using namespace std;

// a = non-polymorphic upcasting:

// Since play in Instrument is not virtual, the function call i.play() inside tune 
// resolves statically at compile time. The compiler does not consider the actual 
// type of the object (Wind) at runtime; it only sees the base class reference (Instrument&).

#define b // Select here (a or b)

#ifdef a

class Instrument {
public:
    void play() const { cout << "Instrument::play" << endl; }
};

class Wind : public Instrument {
public:
    void play() const { cout << "Wind::play" << endl; }
};

void tune(Instrument& i) {
    i.play();
}

int main() {
    Wind flute;
    tune(flute);
}


#endif // end-a
//----------------------------
// b = polymorphic upcasting with virtual functions:

// The play method in Instrument is declared as virtual. This tells the compiler to 
// defer the decision of which play method to call until runtime.
// When tune(flute) is called, the i.play() function dynamically binds to the actual 
// type of the object (Wind), even though it’s accessed through an Instrument&.

#ifdef b
class Instrument {
public:
    virtual void play() const { std::cout << "Instrument::play" << std::endl; }
};

class Wind : public Instrument {
public:
    void play() const override { std::cout << "Wind::play" << std::endl; }
};

void tune(Instrument& i) {
    i.play();
}

int main() {
    Wind flute;
    tune(flute);
}

#endif // end-b