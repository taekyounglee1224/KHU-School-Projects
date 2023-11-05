#include <iostream>
using namespace std;

class Account {
private: 
	string name;
	string idnumber;
	int amount;

public: 
	Account(string name, string idnumber, int amount) : name(name), idnumber(idnumber), amount(amount) {}

	string getID() const {
		return idnumber;
	}

	string getname() const {
		return name;
	}

	int getamount() const {
		return amount;
	}

	Account operator+(Account& acnt) {
		Account result(this->name, this->idnumber, this->amount + acnt.amount);
		return result;
	}
	Account operator-(Account& acnt) {
		Account result(this->name, this->idnumber, this->amount - acnt.amount);
		return result;
	}
	friend ostream& operator<<(ostream& cout, const Account& acnt);

};

ostream& operator<<(ostream& cout, const Account& acnt) {
	cout << "�й�: " << acnt.idnumber << ", �̸�: " << acnt.name << ", �ܾ�: " << acnt.amount;
	return cout;
}

int main() {
	Account acnt[3] = {
	Account("����ȣ", "2014", 10000),
	Account("������", "2019", 0),
	Account("������", "2013", 5000),
	};

	string send;
	string receive;
	int sendcount = -1;
	int receivecount = -1;

	while (true) {
		cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
		cin >> send;

		if (send == "����") {
			cout << "�����մϴ�." << endl;
			for (int i = 0; i < 3; i++)
				cout << acnt[i] << endl;
			break;
		}

		cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
		cin >> receive;
		for (int i = 0; i < 3; i++)
			if (send == acnt[i].getID())
				sendcount = i;
		for (int i = 0; i < 3; i++)
			if (receive == acnt[i].getID())
				receivecount = i;

		if (send == receive) {
			cout << "���� ���� �л��� ���� �л��� �й��� �����մϴ�" << endl;
		}

		else if (sendcount == -1 || receivecount == -1) {
			cout << "������ �л� Ȥ�� ���� �л��� �й��� �������� �ʽ��ϴ�.�ٽ� �Է����ּ���." << endl;
			continue;
		}

		else if (acnt[sendcount].getamount() == 0) {
			cout << "������ �л��� �ܾ��� �����մϴ�." << endl;
			continue;
		}

		else {
			acnt[receivecount] = acnt[receivecount] + acnt[sendcount];
			acnt[sendcount] = acnt[sendcount] - acnt[sendcount];
			cout << "���� �л��� �ܾ� => " << acnt[sendcount] << endl;
			cout << "���� �л��� �ܾ� => " << acnt[receivecount] << endl;
		}
	}
	return 0;
}
