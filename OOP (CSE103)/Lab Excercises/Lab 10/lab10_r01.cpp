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
	CStudent s1; // A
	s1.Display();

	CStudent s2(1999000000, "����ö", "���ؿ�ȭ��"); // B
	s2.Display();

	// C
	s1.setNumber(2006000000);
	s1.setName("�ΰ���");
	s1.setMajor("����Ʈ���");
	cout << "�й� :" << s1.getNumber() << endl;
	cout << "�̸� :" << s1.getName() << endl;
	cout << "���� :" << s1.getMajor() << endl;

	return 0;
}
