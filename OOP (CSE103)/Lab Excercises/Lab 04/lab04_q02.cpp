#include <iostream>

using namespace std;


void print_DOB(int year = 1900, int month = 1, int day = 1);

int main() {
	
	int year, month, day;
	print_DOB();
	cout << "year �Է� : ";
	cin >> year;
	cout << "month �Է� : ";
	cin >> month;
	cout << "day �Է� : ";
	cin >> day;
	print_DOB(year, month, day);
}

void print_DOB(int year, int month, int day) {
	cout << "���������" << year << "��" << month << "��" << day << "�� �Դϴ�" << endl;
}