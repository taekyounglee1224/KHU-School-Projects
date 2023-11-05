#include <iostream>
using namespace std;

class Account {
private:
	int idnum;
	string name;
	int amount;
	static int sum;

public:
	Account(int id = 0000, string name = "", int balance = 0) : idnum(id), name(name), amount(amount) { }
	~Account() {
		sum += amount;
	}
	void setAcnt(int idnum, string name, int amount) {
		this->idnum = idnum;
		this->name = name;
		this->amount = amount;
	}
	int getID() {
		return idnum;
	}
	static int getSum() {
		return sum;
	}
};

int Account::sum = 0;

int main() {
	int studentnum;
	cout << "총 학생 수 입력: ";
	cin >> studentnum;
	Account* acnt = new Account[studentnum];
	int id;
	string name;
	int balance;

	for (int i = 0; i < studentnum; i++) {
		cout << i + 1 << "번째 학생 계좌 입력 : 학번 : ";
		cin >> id;
		for (int j = 0; j < i; j++)
			if (acnt[j].getID() == id)
				exit(100);

		cout << endl;
		cout << "이름 : ";
		cin >> name;
		cout << endl;
		cout << "잔액 : ";
		cin >> balance;
		acnt[i].setAcnt(id, name, balance);
		cout << "==========================" << endl << endl;
	}

	delete[] acnt;
	cout << "회수된 금액 : " << Account::getSum();
	return 0;
}
