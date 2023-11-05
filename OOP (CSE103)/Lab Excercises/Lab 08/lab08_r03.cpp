#include <iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& v1) {
	for (int a = 0; a < v1.size() / 2; a++) {
		int b = v1.size() - 1;
		int temp = v1[a];
		v1[a] = v1[b - a];
		v1[b - a] = temp;
	}

}

int main() {
	vector<int> vec(10);
	for (int k = 0; k < 10; k++)
		vec[k] = k + 1;

	cout << "기본 벡터 값: "  << endl;
	for (unsigned i = 0; i < vec.size(); i++)
		cout << ' ' << vec[i];
		cout << endl;

		reverse(vec);

	cout << "변환된 벡터 값: " << endl;
	for (unsigned i = 0; i < vec.size(); i++)
		cout << ' ' << vec[i];
	cout << endl;

	return 0;
}