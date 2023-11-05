#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
using namespace std;

void makematrix(vector<vector<int>>& m)
{
	for (auto& row : m)
		for (auto& col : row)
			col = (rand() % 19) - 9;
}

void print(const vector<vector<int>>& m)
{
	for (auto& row : m)
	{
		for (auto& col : row)
			cout << setw(4) << col;
		cout << endl;
	}
}

vector<vector<int>> mulMat(vector<vector<int>>& m1, vector<vector<int>>& m2)
{
	vector<vector<int>> m(m1.size(), vector<int>(m2[0].size()));
	for (int k = 0; k < m1.size(); k++)
	{
		for (int l = 0; l < m2[0].size(); l++)
		{
			int mulMatElem = 0;
			for (int i = 0; i < m1[0].size(); i++)
			{
				mulMatElem += m1[k][i] * m2[i][l];
			}
			m[k][l] = mulMatElem;
		}
	}
	return m;
}

int main()
{
	int rowA, colA, rowB, colB;
	srand(time(NULL));

	cout << "A의 행, 열의 크기를 입력해주세요 : ";
	cin >> rowA >> colA;
	vector<vector<int>> A(rowA, vector<int>(colA));
	cout << "B의 행, 열의 크기를 입력해주세요 : ";
	cin >> rowB >> colB;
	vector<vector<int>> B(rowB, vector<int>(colB));
	if (rowA < 1 || colA < 1 || rowB < 1 || colB < 1)
		cout << "행렬을 생성할 수 없습니다." << endl;
	else
	{
		makematrix(A);
		cout << "A 행렬 : " << endl;
		print(A);
		cout << endl;

		makematrix(B);
		cout << "B 행렬 : " << endl;
		print(B);
		cout << endl;

		if (colA != rowB)
			cout << "두 행렬을 곱할 수 없습니다." << endl;
		else
		{
			vector<vector<int>> m;
			m = mulMat(A, B);
			cout << "AB 곱행렬: " << endl;
			print(m);
		}
	}
	return 0;
}
