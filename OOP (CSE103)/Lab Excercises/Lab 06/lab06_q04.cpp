#include <iostream>
using namespace std;

void get_num(int& num);

int main() {
	int sequence = 1;
	int n = 1;
	get_num(n);
	while (n != -1) {
		while (sequence < 10) {
			cout << n << "*" << sequence << "=" << n * sequence << endl;
			sequence++;
		}
		cout << endl;
		sequence = 1;
		get_num(n);
	}	
	
}

void get_num(int& num) {
	cout << "�� ���� �Է��ϼ���: ";
	cin >> num;

	if (num == -1) {
		cout << "�����մϴ�";
	}
	else if (num < 1 || num>9) {
		cout << "1���� 9���� ������ �Է����ּ���" << endl;
		get_num(num);
	}
	
}