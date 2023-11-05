#include <iostream>

using namespace std;

void swap_call_by_value(int x, int y);
void swap_call_by_reference(int& x, int& y);

int main() {
	int x, y;

	cout << "swap_call_by_value �Լ� ��� ��" << endl << "x = " << x << ", y = " << y << endl;
	swap_call_by_value(x, y);
	cout << "swap_ call_by_value �Լ� ��� ��" << endl;
	cout << "x = " << x << ", y = " << y << endl;

	cout << "swap_call_by_reference �Լ� ��� ��" << endl << "x = " << x << ", y = " << y << endl;
	swap_call_by_reference(x, y);
	cout << "swap_call_by_reference �Լ� ��� ��" << endl;
	cout << "x = " << x << ", y = " << y << endl;

}

void swap_call_by_value(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

void swap_call_by_reference(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

	
