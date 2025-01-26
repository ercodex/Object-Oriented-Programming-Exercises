#include <iostream>
using namespace std;

/*
    Bu kod, C++'ta polimorfizmi ve statik/dinamik bağlamayı (binding) örneklemektedir.

    1. Base sınıfından türeyen Derived sınıfı:
       - Base: Sanal (virtual) ve sanal olmayan (non-virtual) fonksiyonlar içerir.
       - Derived: Bu fonksiyonları kendi davranışlarına göre yeniden tanımlar (override eder).

    2. Statik ve Dinamik Bağlama:
       - Statik Bağlama (Compile-time Binding): Sanal olmayan fonksiyonlar derleme zamanında çözülür. 
         Örneğin, obj->nonVirtualFunc() çağrısı Base sınıfının fonksiyonunu çalıştırır.
       - Dinamik Bağlama (Run-time Binding): Sanal (virtual) fonksiyonlar çalışma zamanında çözülür.
         Örneğin, obj->virtualFunc() çağrısı Derived sınıfının fonksiyonunu çalıştırır.

    3. Base* işaretçi kullanımı:
       - Base* obj = new Derived(); ile Base sınıfından bir işaretçi, Derived nesnesini işaret eder.
       - Bu yapı, çok biçimliliği (polimorfizm) ve türetilmiş sınıfların dinamik olarak davranışlarını değiştirmesini sağlar.

    4. Çıktılar:
       - obj->nonVirtualFunc(): "Base: Sanal olmayan fonksiyon" (Statik bağlama nedeniyle).
       - obj->virtualFunc(): "Derived: Sanal fonksiyon" (Dinamik bağlama sayesinde).

    Özet: C++'ta sanal fonksiyonlar, vtable ve vptr mekanizması ile çalışma zamanında doğru fonksiyonu çağırır.
*/
class Base {
public:
    void nonVirtualFunc() {
        cout << "Base: Sanal olmayan fonksiyon" << endl;
    }
    virtual void virtualFunc() {
        cout << "Base: Sanal fonksiyon" << endl;
    }
};

class Derived : public Base {
public:
    void nonVirtualFunc() {
        cout << "Derived: Sanal olmayan fonksiyon" << endl;
    }
    void virtualFunc() override {
        cout << "Derived: Sanal fonksiyon" << endl;
    }
};

int main() {
    Base* obj = new Derived();

    // Statik bağlama: Base sınıfındaki fonksiyon çağrılır.
    obj->nonVirtualFunc();  // Çıktı: Base: Sanal olmayan fonksiyon

    // Dinamik bağlama: Derived sınıfındaki fonksiyon çağrılır.
    obj->virtualFunc();     // Çıktı: Derived: Sanal fonksiyon

    delete obj;
    return 0;
}
