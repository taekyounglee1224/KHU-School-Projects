#include <iostream>
#include "director.h"

using namespace std;

int main()
{

    int vacationtype;
    do
    {
        cout << "Enter Type of Vacation (1, 2, 3): ";
        cin >> vacationtype;
    } while (vacationtype < 1 || vacationtype > 3);
    // ���� ��ȹ Ȯ��
    Director::book(vacationtype);
    return 0;
}