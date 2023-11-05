#include <iostream>

using namespace std;

int main() {
	char grade = 'X';
	int score;
	cout << "Enter your score" << endl;
	cin >> score;
	
	if (0 <= score && score <= 100) {
		if (score >= 90) {
			cout << "Your grade is " << 'A' << endl;
		}
		else if (score >= 80) {
			cout << "Your grade is " << 'B' << endl;
		}
		else if (score >= 70) {
			cout << "Your grade is " << 'C' << endl;
		}
		else if (score >= 60) {
			cout << "Your grade is " << 'D' << endl;
		}
		else
			cout << "Your grade is " << 'F' << endl;
	}
	else
		cout << "Your score is invalid" << endl;
	return 0;
}