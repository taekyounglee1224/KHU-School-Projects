#include <iostream>
using namespace std;

class CStudent {
private:
	int id;
	string name;
	string major;

public:
	CStudent() : id(2018000000), name("ȫ�浿"), major("��ǻ�Ͱ��а�")
	{}
	CStudent(int _id, string _name, string _major) : id(_id), name(_name), major(_major)
	{}

	void Display() {
		cout << "�й� :" << id << endl;
		cout << "�̸� :" << name << endl;
		cout << "���� :" << major << endl << endl;
	}
	void setNumber(int _id) {
		id = _id;
	}
	void setName(string _name) {
		name = _name;
	}
	void setMajor(string _major) {
		major = _major;
	}
	int getNumber() {
		return id;
	}
	string getName() {
		return name;
	}
	string getMajor() {
		return major;
	}
};

int main() {
	CStudent s[3]; 
	int inputNumber; 
	string inputName, inputMajor; 
	int length = 0; 

	while (1) {
		cout << (length + 1) << " ��° �л� �Է�" << endl;
		cout << "�й� : ";
		cin >> inputNumber;
		cout << "�̸� : ";
		cin >> inputName;
		cout << "���� : ";
		cin >> inputMajor;


		s[length] = CStudent(inputNumber, inputName, inputMajor);

		bool checking = true;

		for (int i = 0; i < length; i++) {
			if (s[i].getNumber() == inputNumber) {
				checking = false;
			}
		}
		if (checking == false) {
			cout << "���ߺ��� �й��� �����մϴ�" << endl << endl; \
				checking = true;
		}
		else if (checking == true) {
			cout << "���Է� �Ϸ�" << endl << endl;
			length++;
		}

		if (length == 3)
		{
			cout << "----����Է��� �Ϸ�Ǿ����ϴ�----" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << "�л�����" << endl;
				s[i].Display();
			}
			exit(100);
		}
	}

	return 0;
}
