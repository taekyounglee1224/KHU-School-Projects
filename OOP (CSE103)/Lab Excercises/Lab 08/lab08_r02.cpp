#include <iostream>
using namespace std;

void change(string* s1) {
	string input;
	cout << "input: ";
	cin >> input;
	*s1 = input;
}

int main() {
	string str = "This is a default value";
	cout << "�⺻�� ���>" << str << endl;
	change(&str);
	cout << "��ȯ�� �� ���>" << str << endl;

	return 0;
}