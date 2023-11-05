#include <iostream>
using namespace std;

int get_num();
int addmul(int x, int y, int z);
float muldiv(int x, int y, int z);
int addmuladd(int x, int y, int z);
float subdivsub(int x, int y, int z);

int get_num() {
	int num;
	cout << "Enter a number: " << endl;
	cin >> num;
	return num;
}

int addmul(int x, int y, int z) {
	return (x + y) * z;
}
float muldiv(int x, int y, int z) {
	return (float(x) * float(y)) / float(z);
}
int addmuladd(int x, int y, int z) {
	return (x + y) * (y + z);
}
float subdivsub(int x, int y, int z) {
	return ((float(x) -float(y)) / (float(y) - float(z)));
}

int main() {
	int x, y, z;
	x = get_num();
	y = get_num();
	z = get_num();
	cout << "x= " << x << " y= " << y << " z= " << z << endl;
	cout << "(x + y) * z = " << addmul(x, y, z) << endl;
	cout << "(x * y) / z = " << muldiv(x, y, z) << endl;
	cout << "(x + y) * (y + z) = " << addmuladd(x, y, z) << endl;
	cout << "(x - y) / (y - z) = " << subdivsub(x, y, z) << endl;
}