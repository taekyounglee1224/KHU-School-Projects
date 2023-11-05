#include <iostream>
using namespace std;
int main() {
	int num = 1, input;
		while (num <= 5) {
			cout << num << "번째 정수: ";
			cin >> input;
			if (input % 2 == 0) {
				cout << input << "는 짝수입니다" << endl;
			}
			else {
				cout << input << "는 홀수입니다" << endl;
			}
			num++;
	}
		return 0;
}