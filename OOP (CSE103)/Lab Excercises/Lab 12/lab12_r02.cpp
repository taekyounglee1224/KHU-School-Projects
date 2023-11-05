#include <iostream>
#include <cmath>
using namespace std;

class Polygon {
public:
	Polygon() {}
	Polygon(int point, float length) { tPoint = point, tLength = length; }
	~Polygon() {}
	virtual void Perimeter() { cout << "Perimeter: empty" << endl; }
	virtual void Area() { cout << "Area: empty" << endl; }
protected:
	int tPoint; 
	double tLength; 
};

class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) : Polygon(point, length) {}
	~Rectangle() {}
	void Perimeter() override { cout << "Perimeter: " << Polygon::tPoint * Polygon::tLength << endl; }
	void Area() override { cout << "Area: " << pow(Polygon::tLength,2) << endl; }
};

class Triangle : public Polygon {
public:
	Triangle() {}
	Triangle(int point, float length) : Polygon(point, length) {}
	~Triangle() {}
	void Perimeter() override { cout << "Perimeter: " << Polygon::tPoint * Polygon::tLength << endl; }
	void Area() override { cout << "Area: " << pow(Polygon::tLength,2) * (sqrt(3) / 4) << endl; }
};

class Circle : public Polygon {
public:
	Circle() {}
	Circle(int point, float length) : Polygon(point, length) {}
	~Circle() {}
	void Perimeter() override { cout << "Perimeter: " << 2 * 3.14 * Polygon::tLength << endl; }
	void Area() override { cout << "Area: " << pow(Polygon::tLength,2) * 3.14 << endl; }
};


int main() {
	Polygon pol;
	Rectangle rec(4, 10);
	Triangle tri(3, 10);
	Circle cir(0, 5);

	cout << "--- Rectangle class ---" << endl;
	rec.Perimeter();
	rec.Area();
	cout << "--- Triangle class ---" << endl;
	tri.Perimeter();
	tri.Area();
	cout << "--- Circle class ---" << endl;
	cir.Perimeter();
	cir.Area();
	return 0;
}

