#include <iostream>
using namespace std;
int main() {
	int sum = 0, num;
	int i = 1;
	while (i <= 100) {
        sum += i;
		i++;
	}
	cout << "number: ";
	cin >> num;
	cout << "Sum from 1 to " << num << ": " << sum << endl;
	return 0;
}