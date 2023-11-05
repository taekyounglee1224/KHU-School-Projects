#include <iostream>
using namespace std;

void get_numbers(int& num1, int& num2);
void gcd(int& a, int& b);


int main() {

	int a, b; // ¸ò ÀÌ¶û ÃÖ´ë°ø¾à¼ö µîµî
	int x, y;
	get_numbers(x, y);

	if (x > y) {
		a = x;
		b = y;
		gcd(a, b);
	}
	else {
		a = y;
		b = x;
		gcd(a, b);
	}


	cout << "gcd(" << x << "," << y << ") = " << b << endl;
}

void get_numbers(int& num1, int& num2) {

	cout << "x = ";
	cin >> num1;
	cout << "y = ";
	cin >> num2;
}

void gcd(int& a, int& b) {

	if (b == 0)
		b = a;
	else if (b > 0) {
		int c;
		c = b;
		b = a % b;
		a = c;
		gcd(a, b);
	}

}
