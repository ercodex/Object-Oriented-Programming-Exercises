#include <iostream>
using namespace std;

class Shape {
private:
	int x;
	int y;
public:
	
	// Constructor
	Shape(int X = 0, int Y = 0) : x(X), y(Y) { // When not specified, create objects at origin (0, 0)
		cout << "Shape Constructor" << endl;
	}

	// Set coordinate
	void setCoord(int X, int Y) {
		x = X;
		y = Y;
	}

	int getX() const {
		return x;
	}
	
	int getY() const { 
		return y;
	}

	virtual void printCoord() const { // This function works "read-only", so it is a const.
		cout << "(" << x << ", " << y << ")" << endl;
	}

	~Shape() {
		cout << "Shape Destructor" << endl;
	}

};

class Circle : public Shape { // has - a (Composition) 
private:
	float radius;
public:
	Circle(int X = 0, int Y = 0, float r = 0) : Shape(X, Y), radius (r) {
		cout << "Circle Constructor" << endl;
	}

	void setRadius(float r) {
		radius = r;
	}

	float circleArea() const {
		return (3.14 * radius * radius);
	}

	float circleLength() const {
		return (2 * 3.14 * radius);
	}
	~Circle() {
		cout << "Circle Destructor" << endl;
	}
};

class Sphere : public Shape { // has - a (Composition)
private:
	int z;
	float radius;
public:

	// Constructor
	Sphere(int X = 0, int Y = 0, int Z = 0) : Shape(X, Y), z(Z) {
		cout << "Sphere Constructor" << endl;
	};

	// Redesigned printCoord() function for Sphere class 
	// You can make x and y protected to make them open to use for derived classes.
	void printCoord() const override {
		cout << "(" << getX() << ", " << getY() << ", " << z << ")" << endl;
	}

	float sphereSurfaceArea() const {
		return (4 * 3.14 * radius * radius);
	}

	float sphereVolume() const {
		return ((4 / 3) * 3.14 * radius * radius * radius);
	}

	void setRadius(float r) {
		radius = r;
	}

	~Sphere(){
		cout << "Sphere Destructor" << endl;
	}

};

int main() {
	Circle c1;
	c1.printCoord();

	c1.setCoord(3, 4);
	c1.printCoord();

	c1.setRadius(5);
	cout << "Circle area  : " << c1.circleArea() << endl;
	cout << "Circle length: " << c1.circleLength() << endl;
	cout << "---------------------------" << endl;

	Sphere sp1;
	sp1.printCoord();

	sp1.setCoord(5, 6);
	sp1.printCoord();

	sp1.setRadius(7);
	cout << "Sphere surface area  : " << sp1.sphereSurfaceArea() << endl;
	cout << "Sphere volume        : " << sp1.sphereVolume() << endl;

	return 0;
}