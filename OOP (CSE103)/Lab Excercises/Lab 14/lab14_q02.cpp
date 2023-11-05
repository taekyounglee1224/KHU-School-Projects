#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//����ó��: try/catch����, throw��
//1. ���ܰ� �߻��ϴ� �κ��� try�� �ִ´�
//2. ���ܰ� �߻��ϸ� catch ������ ����ȴ�
class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(string _m) :
		message("File not found: " + _m) {}
	virtual const char* what() const throw() {
		return message.c_str();
	}

};
vector<int> load_vector(string filename) {
	ifstream fin(filename);

	// ������ ������ ������(������ ��������x)
	if (!fin) {
		// ����ó�� (throw)
		throw FileNotFoundException(filename);
	}

	vector<int> result;
	int num, value;
	// ���Ϸκ��� ���� result�� ����
	// ������ form: size, elements (5 1 2 3 4 4)
	fin >> num;
	for (int i = 0; i < num; i++) {
		fin >> value;
		result.push_back(value);
	}
	return result;
}
int main() {
	try {
		auto v = load_vector("values.dat"); // values.dat ���Ͽ��� vector �ε�
		for (int elem : v)
			cout << elem << ' ';
		cout << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}
