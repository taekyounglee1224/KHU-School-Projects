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
	cout << "기본값 출력>" << str << endl;
	change(&str);
	cout << "변환된 값 출력>" << str << endl;

	return 0;
}