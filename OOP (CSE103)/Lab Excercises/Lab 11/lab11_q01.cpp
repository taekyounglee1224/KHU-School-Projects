#include <iostream>
using namespace std;

class Point {
	int x;
	int y;
	static int numCreatedObjects;
public: 
	Point() : x(0), y(0) {
		numCreatedObjects++;
	}

	Point(int _x, int _y) : x(_x), y(_y) {
		numCreatedObjects++;
	}

	~Point() {
		cout << "Destructed..." << endl; 
	}

	void setXY(int _x, int _y) {
		this->x=_x;
		this->y=_y;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	Point operator+(Point& pt2) {
		Point result(this->x + pt2.getX(), this->y + pt2.getY());
		return result;
	}

	Point& operator=(Point& pt) {
		this->x = pt.getX();
		this->y = pt.getY();
		return (*this);
	}

	static int getNumCreatedObject() { return numCreatedObjects; }
	friend void print(const Point& pt);
	friend ostream& operator<<(ostream& cout, Point& pt);
	friend class SpyPoint;

};

int Point::numCreatedObjects = 0;

void print(const Point& pt) {
	cout << pt.x << " " << pt.y << endl;
}

ostream& operator<<(ostream& cout, Point& pt) {
	cout << pt.x << ", " << pt.y << endl;
	return cout;
}

class SpyPoint {
public:
	void hack_all_info(const Point& pt) {

		cout << "Hacked by Spypoint" << endl;
		cout << "x: " << pt.x << endl;
		cout << "y: " << pt.y << endl;
		cout << "numCreatedObj.: " << pt.numCreatedObjects << endl << endl;

	}
};

int main() {
	Point pt1(1, 2);
	cout << "pt1 :";
	print(pt1);

	cout << endl;

	Point* pPt1 = &pt1;

	cout << "pt1 : ";
	cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	cout << "pt1 : ";

	cout << pPt1->getX() << ", " << pPt1->getY() << endl;
	cout << endl;

	Point* pPt2 = new Point(10, 20);
	cout << "pt2 : ";
	cout << pPt2->getX() << ", " << pPt2->getY() << endl;
	cout << endl;

	pPt1->~Point();
	delete pPt2;

	cout << "pt1 NumCreatedObjects ";
	cout << pt1.getNumCreatedObject() << endl;

	Point pt2(10, 20), pt3(30, 40);
	Point pt4 = pt2 + pt3;
	cout << "pt2 : ";
	cout << pt2 << endl;
	cout << "pt3 : ";
	cout << pt3 << endl;
	cout << "pt4 : ";
	cout << pt4 << endl;

	cout << "pt1 NumCreatedObject : ";
	cout << pt1.getNumCreatedObject() << endl << endl;


	Point* ptAry = new Point[5];
	cout << "pt2 NumCreatedObject : ";
	cout << pt2.getNumCreatedObject() << endl;
	cout << endl;

	delete[] ptAry;

	cout << endl;

	
	SpyPoint spy;
	cout << "pt1 info" << endl;
	spy.hack_all_info(pt1);
	cout << "pt4 info" << endl;
	spy.hack_all_info(pt4);

	return 0;

}