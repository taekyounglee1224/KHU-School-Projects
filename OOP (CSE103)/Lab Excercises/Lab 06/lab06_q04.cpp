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
	cout << "단 수를 입력하세요: ";
	cin >> num;

	if (num == -1) {
		cout << "종료합니다";
	}
	else if (num < 1 || num>9) {
		cout << "1부터 9까지 정수를 입력해주세요" << endl;
		get_num(num);
	}
	
}