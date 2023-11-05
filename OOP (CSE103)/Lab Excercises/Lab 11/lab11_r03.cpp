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
	cout << "�� �л� �� �Է�: ";
	cin >> studentnum;
	Account* acnt = new Account[studentnum];
	int id;
	string name;
	int balance;

	for (int i = 0; i < studentnum; i++) {
		cout << i + 1 << "��° �л� ���� �Է� : �й� : ";
		cin >> id;
		for (int j = 0; j < i; j++)
			if (acnt[j].getID() == id)
				exit(100);

		cout << endl;
		cout << "�̸� : ";
		cin >> name;
		cout << endl;
		cout << "�ܾ� : ";
		cin >> balance;
		acnt[i].setAcnt(id, name, balance);
		cout << "==========================" << endl << endl;
	}

	delete[] acnt;
	cout << "ȸ���� �ݾ� : " << Account::getSum();
	return 0;
}
