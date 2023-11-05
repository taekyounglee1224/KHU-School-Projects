#include <iostream>

using namespace std;

int main() {
	int num;
	do {
		cout << "Enter a number (0,10]: " << endl;
		cin >> num;
	} while (num>10 or num<=0);
	cout << "Success" << endl;
	return 0;
}
