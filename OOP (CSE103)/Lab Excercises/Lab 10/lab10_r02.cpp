#include <iostream>
using namespace std;

class CStudent {
private:
	int id;
	string name;
	string major;

public:
	CStudent() : id(2018000000), name("홍길동"), major("컴퓨터공학과")
	{}
	CStudent(int _id, string _name, string _major) : id(_id), name(_name), major(_major)
	{}

	void Display() {
		cout << "학번 :" << id << endl;
		cout << "이름 :" << name << endl;
		cout << "전공 :" << major << endl << endl;
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
		cout << (length + 1) << " 번째 학생 입력" << endl;
		cout << "학번 : ";
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공 : ";
		cin >> inputMajor;


		s[length] = CStudent(inputNumber, inputName, inputMajor);

		bool checking = true;

		for (int i = 0; i < length; i++) {
			if (s[i].getNumber() == inputNumber) {
				checking = false;
			}
		}
		if (checking == false) {
			cout << "※중복된 학번이 존재합니다" << endl << endl; \
				checking = true;
		}
		else if (checking == true) {
			cout << "※입력 완료" << endl << endl;
			length++;
		}

		if (length == 3)
		{
			cout << "----모든입력이 완료되었습니다----" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << "학생정보" << endl;
				s[i].Display();
			}
			exit(100);
		}
	}

	return 0;
}
