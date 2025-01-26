#include <iostream>
using namespace std;

class Point3D {
private:
    double x, y, z;

public:
    // Constructor
    Point3D(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) {}

    // Getter fonksiyonlar
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // << Operatörünün overload edilmesi (Arkadaş fonksiyonu olarak tanımlanıyor)
    friend ostream& operator<<(ostream &os, const Point3D &p){
        os << "Point(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";
        return os;  // Zincirleme operatörler için ostream döndürülüyor
    }

    // - Operatörünü overload etme
    Point3D operator-(const Point3D &p){
        return Point3D(x - p.x, y - p.y, z - p.z);  // Her koordinatı ayrı ayrı çıkarıyoruz
    }
};

int main(){
    Point3D p1(3, 4, 5);
    Point3D p2(6, 7, 8);

    // Operatör overload'u sayesinde direkt cout ile yazdırabiliriz
    cout << p1 << endl;
    cout << p2 << endl;

    // Çıkarma işlemi
    cout << p2 - p1 << endl;  // Sonuç: Point(3, 3, 3)

    return 0;
}
