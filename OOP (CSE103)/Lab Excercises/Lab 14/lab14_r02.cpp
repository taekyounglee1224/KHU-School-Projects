#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class FileNotFoundException : public exception {
	string message; // Identifies the exception and filename
public:
	FileNotFoundException(const string& fname) :
		message("File \"" + fname + "\" not found") {}

	virtual const char* what() const throw () {
		return message.c_str();
	}
};
class CStudent
{
private:
	string m_Name;
	int m_Number;
	string m_Major;
public:
	CStudent() {}
	~CStudent() {}
	void setAll(string _name, int _num, string _maj) {
		m_Name = _name;
		m_Number = _num;
		m_Major = _maj;
	}
	void Display() {
		cout << "�̸�: " << m_Name << endl;
		cout << "�й�: " << m_Number << endl;
		cout << "����: " << m_Major << endl << endl;
	}
};
vector<CStudent> read_file(string& filename) {
	ifstream fin(filename);
	if (!fin)
		throw FileNotFoundException(filename);

	vector<CStudent> data;

	string name;
	int number;
	string major;

	int n;
	fin >> n;

	for (int i = 0; i < n; i++) {
		fin >> name >> number >> major;
		CStudent temp;
		temp.setAll(name, number, major);
		data.push_back(temp);
	}

	return data;
}
int main() {
	string str;

	cout << "���� �̸� : ";
	cin >> str;

	try {
		vector<CStudent> numbers = read_file(str);
		for (CStudent value : numbers)
			value.Display();
	}
	catch (std::exception& e) {
		cout << e.what() << '\n';
	}

	return 0;
}
