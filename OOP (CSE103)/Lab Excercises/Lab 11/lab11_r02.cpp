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
	cout << "학번: " << acnt.idnumber << ", 이름: " << acnt.name << ", 잔액: " << acnt.amount;
	return cout;
}

int main() {
	Account acnt[3] = {
	Account("장윤호", "2014", 10000),
	Account("김유민", "2019", 0),
	Account("박진배", "2013", 5000),
	};

	string send;
	string receive;
	int sendcount = -1;
	int receivecount = -1;

	while (true) {
		cout << "돈을 보낼 학생의 학번을 입력하세요: ";
		cin >> send;

		if (send == "종료") {
			cout << "종료합니다." << endl;
			for (int i = 0; i < 3; i++)
				cout << acnt[i] << endl;
			break;
		}

		cout << "돈을 받을 학생의 학번을 입력하세요: ";
		cin >> receive;
		for (int i = 0; i < 3; i++)
			if (send == acnt[i].getID())
				sendcount = i;
		for (int i = 0; i < 3; i++)
			if (receive == acnt[i].getID())
				receivecount = i;

		if (send == receive) {
			cout << "돈을 보낸 학생과 받은 학생의 학번이 동일합니다" << endl;
		}

		else if (sendcount == -1 || receivecount == -1) {
			cout << "보내는 학생 혹은 받은 학생의 학번이 존재하지 않습니다.다시 입력해주세요." << endl;
			continue;
		}

		else if (acnt[sendcount].getamount() == 0) {
			cout << "보내는 학생의 잔액이 부족합니다." << endl;
			continue;
		}

		else {
			acnt[receivecount] = acnt[receivecount] + acnt[sendcount];
			acnt[sendcount] = acnt[sendcount] - acnt[sendcount];
			cout << "보낸 학생의 잔액 => " << acnt[sendcount] << endl;
			cout << "받은 학생의 잔액 => " << acnt[receivecount] << endl;
		}
	}
	return 0;
}
