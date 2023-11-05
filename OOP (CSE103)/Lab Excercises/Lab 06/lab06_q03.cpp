#include <iostream>
using namespace std;
int main() {
	int sum = 0, num;
	int i = 1;
	while (i <= 50) {
		if (i % 2 != 0 && i % 3 != 0) {
			sum += i;
			i++;
		}
		else {
			sum += 0;
			i++;

		}
	}	
	cout << "number: ";
	cin >> num;
	cout << "sum: "<< sum << endl;
	return 0;
}