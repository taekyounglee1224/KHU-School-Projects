#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int n, m;
	cout << "Enter n for n x m matrix: ";
	cin >> n;
	cout << "Enter m for n x m matrix: ";
	cin >> m;
	
	int row = 1;
	while (row <= n) {
		int column = 1;
		while (column <= m) {
			int product = column * row;
			cout << setw(4) << product;
			column++;
		}
		cout << '\n';
		row++;
	}
	return 0;
}

