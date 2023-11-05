#include <iostream>
#include <fstream>
#include <vector>
#include <random>
using namespace std;

class FileNotFoundException : public exception {
	string message; 
public:
	FileNotFoundException(const string& fname) :
		message("File \"" + fname + "\" not found") {}

	virtual const char* what() const throw () {
		return message.c_str();
	}
};

int main()
{
	ofstream ofs;
	ofs.open("temp.txt");

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			ofs << rand() % 101 << ' ';
		ofs << endl;
	}
	vector<vector<int>> v(10);
	for (vector<int>& elem : v)
		elem = vector<int>(10);
	
	ofs.close();

	try {
		string filename;
		cout << "���� �̸�: ";
		cin >> filename;
		ifstream fin(filename);
		if (!fin)
			throw FileNotFoundException(filename);

		int val;
		for (vector<int>& row : v)
			for (int& elem : row) {
				fin >> val;
				elem = val;
			}

		fin.close();

		int r, c;

		cout << "����� �� ũ��: ";
		cin >> r;
		cout << "����� �� ũ��: ";
		cin >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << v.at(i).at(j) << ' ';
			}
			cout << endl;
		}
	}
	catch (exception& e) {
		cout << endl;
		cout << e.what() << endl;
	}
	
	return 0;
}
