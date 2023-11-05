#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Vacation {
public:
	virtual void bookHotels();
	virtual void bookFlights();
	virtual void bookTours();
};

class Package1 : public Vacation {
public:
	void bookHotels() override;
	void bookFlights() override;

};

class Package2 : public Vacation {
public:
	void bookHotels() override;
	void bookTours() override;

};

class Package3 : public Vacation {
public:
	void bookHotels() override;
	void bookFlights() override;
	void bookTours() override;

};

class Director {
public:
	static Vacation* vacation;
	static void book(int num);
};


#endif
