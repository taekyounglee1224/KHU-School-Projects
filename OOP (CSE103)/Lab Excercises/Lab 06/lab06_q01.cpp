#include <iostream>
using namespace std;
int main() {
	int num = 1, input;
		while (num <= 5) {
			cout << num << "��° ����: ";
			cin >> input;
			if (input % 2 == 0) {
				cout << input << "�� ¦���Դϴ�" << endl;
			}
			else {
				cout << input << "�� Ȧ���Դϴ�" << endl;
			}
			num++;
	}
		return 0;
}