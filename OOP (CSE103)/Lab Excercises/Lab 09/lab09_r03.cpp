#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
using namespace std;


bool Checking(int* x, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (x[i] == x[j] && i != j)
				return true;
	return false;
}


int main() {
	srand(time(NULL));

	int n = 0;
	int size;

	while (true) {
		cout << "Please enter a number: ";
		cin >> n;
		size = n / 2;
		if (n < 2) {
			cout << "Wrong number!!!" << endl;
			exit(0);
		}

		cout << "Size of random array: " << size << endl;

		int* x = new int[size];

		cout << "[ Array ]" << endl;
		for (int i = 0; i < size; i++) {
			x[i] = rand() % n + 1;
			cout << x[i] << ' ';
		}

		cout << endl;

		if (Checking(x, size) == true)
			cout << "Duplicates found.\n" << endl;
		else
			cout << "Duplicates not found.\n" << endl;
	}

	return 0;
}
