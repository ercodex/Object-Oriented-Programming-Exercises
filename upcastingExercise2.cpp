#include <iostream>

class Base {
public:
    //virtual void f1() { std::cout << "Base::f1" << std::endl; }
    void f1() { std::cout << "Base::f1" << std::endl; }
    virtual void f2() { std::cout << "Base::f2" << std::endl; }
};

class Derived : public Base {
public:
    //void f1() override { std::cout << "Derived::f1" << std::endl; }
    void f1() { std::cout << "Derived::f1" << std::endl; }
    void f2() override { std::cout << "Derived::f2" << std::endl; }
};

int main() {
    Derived d;
    Base* b = &d;

    b->f1();
    b->f2();

    return 0;
}

// Output: 
//     Base::f1
//     Derived::f2    

// What happens if f1 declared as virtual?

// New Output:
//     Derived::f1
//     Derived::f2

/*
Sanal değilse (non-virtual): Taban sınıf işlevi çağrılır.
Sanal ise (virtual): Çalışma zamanında nesnenin gerçek türüne bakılır ve doğru işlev çağrılır

İşaretçi türü (Base*), hangi üyelerin erişilebilir olduğunu belirler.
Nesnenin gerçek türü (Derived), hangi sanal işlevin çağrılacağını belirler.

Dinamik bağlama (Late binding), sadece sanal (virtual) fonksiyonlar 
için ve taban sınıfın adresi kullanılıyorsa gerçekleşir.

    Bu tanım tamamen doğru. Ama kafa karışıklığı şu noktada:
    "Taban sınıfın adresi kullanılıyor" ifadesi, fiziksel bellek adresinden ziyade taban 
    sınıf türünde bir işaretçi (pointer) veya referans (reference) kullanılmasını ifade eder.

*/

