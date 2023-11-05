#include <iostream>
#include <string>
using namespace std;

template <class Iter>
string Reverse(Iter iter_begin, Iter iter_end) {
	string result;
	iter_end--;
	for (Iter iter = iter_end; iter != iter_begin; iter--)
		result += *iter;
	result += *iter_begin;
	return result;
}

template<class T>
bool evaluate(bool(*func)(T, T), T x, T y) {
	return func(x, y);
}

int main() {
	string text;
	string result;

	while (true) {
		cout << endl;
		cout << "���ڿ� �ϳ��� �Է����ּ��� : ";
		cin >> text;

		if (text == "Q" || text == "q")
			break;

		result = Reverse(begin(text), end(text));
		cout << "�Է��Ͻ� ���ڿ��� ���� : " << result << endl;

		if (evaluate<string>([](string x, string y) { return x == y; }, text, result)) {
			cout << "�� ���ڴ� ȸ���Դϴ�.";
			cout << endl;
		}
		else {
			cout << "�� ���ڴ� ȸ���� �ƴմϴ�.";
			cout << endl;
		}

	}
}
