#include <iostream>
#include <string>
#include<cassert>
#include "director.h"
using namespace std;

Vacation*Director::vacation = 0;
void Vacation::bookFlights() {}
void Vacation::bookHotels() { }
void Vacation::bookTours() { }
void Package1::bookHotels() { cout << "Hotels are booked." << endl; }
void Package1::bookFlights() { cout << "Filghts are booked." << endl; }
void Package2::bookHotels() { cout << "Hotels are booked." << endl; }
void Package2::bookTours() { cout << "Tours are booked." << endl; }
void Package3::bookFlights() { cout << "Filghts are booked." << endl; }
void Package3::bookHotels() { cout << "Hotels are booked." << endl; }
void Package3::bookTours() { cout << "Tours are booked." << endl; }


// 클라이언트가 호출할 정적 멤버 함수 정의
void Director::book(int packageType)
{
    if (packageType == 1)
    {
        vacation = new Package1();
    }
    else if (packageType == 2)
    {
        vacation = new Package2();
    }
    else if (packageType == 3)
    {
        vacation = new Package3();
    }
    cout << "Information about the vacation plan: " << endl;
    vacation->bookHotels();
    vacation->bookFlights();
    vacation->bookTours();
    cout << endl;
}
