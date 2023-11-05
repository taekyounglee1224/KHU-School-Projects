#include <iostream>
#include <cmath>
using namespace std;

class Point {
private: 
	int x;
	int y;

public: 
	Point(int x = 0, int y = 0) :x(x), y(y) {}

		void getPoint(int x, int y) {
			this->x = x;
			this->y = y;
		}

		int getX() const {
			return x;
		}

		int getY() const {
			return y;
		}

		Point operator-(const Point pt) {
			Point result(this->x - pt.x, this->y - pt.y);
			return result;
		}
	
		Point operator*(const Point pt) {
			Point result(this->x * pt.x, this->y * pt.y);
			return result;
		}
};

int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Point* pP1, * pP2, * pP3;
	cout << "ù��° ��ǥ(x1, y1)�� �Է��ϼ��� : ";
	cin >> x1 >> y1;
	cout << "�ι�° ��ǥ(x2, y2)�� �Է��ϼ��� : ";
	cin >> x2 >> y2;
	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point(); 
	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);
	
	double twopointdist = sqrt(pP3->getX() + pP3->getY());
	cout << "�� ��ǥ ������ ���̴� " << twopointdist << "�Դϴ�." << endl;
	return 0;
}