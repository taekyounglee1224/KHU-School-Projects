#include <iostream>
#include <ctime>
#include <random>
#include <vector>
using namespace std;

int main() {
    vector<int> list;
    srand(time(NULL));
    int n = (rand() % 100 + 1);
    list.resize(n);
    for (int i = 0; i < n; i++) {
        list[i] = i;
    }

    int size = list.size();
    cout << "���� list�� " << size << "�� ũ�⸦ ������ �ִ�" << endl;
    return 0;
}
