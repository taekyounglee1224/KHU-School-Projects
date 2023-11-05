#include <iostream>

using namespace std;

void square(int* x) {
	 (*x)= (*x)* (*x);
}

int main() {
	int a;
	cout << "input: ";
	cin >> a;
	square(&a);
	cout << "square: " << a << endl;

	return 0;
}