#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n = 0;
	while (n % 2 == 0 || n == 1) {
		cout << "Ȧ�� ���ڸ� �ϳ� �Է��� �ּ��� : " << endl;
		cin >> n;
	}

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = -1;

	int i = 0;
	int j = n / 2;
	int cnt = 0;

	while (cnt < n * n) {
		arr[i][j] = ++cnt;
		if ((i > 0 && j < n - 1) && arr[i - 1][j + 1] != -1 || (i == 0 && j == n - 1)) {
			i++;
		}
		else {
			i--; j++;
		}
		if (i < 0)
			i = n - 1;
		else if (j == n)
			j = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
	delete[] arr;

	return 0;
}

