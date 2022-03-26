#pragma once

#include <iostream>

using std::string;
using namespace std;

class Car {
public:
	Car();
	Car(string mk, string md, string b, unsigned int p);
	
	unsigned int GetPrice();

	friend ostream& operator<<(ostream& out, Car& car);
	friend istream& operator>>(istream& out, Car& car);

protected:
	string make;
	string model;
	string body;
	unsigned int price=0;
};