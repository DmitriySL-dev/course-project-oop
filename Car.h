#pragma once

#include <iostream>

using std::string;
using namespace std;

class Car {
public:
	Car();
	Car(string mk, string md, string b, string p);
	friend ostream& operator<<(ostream& out, Car& car);

private:
	string make;
	string model;
	string body;
	string price;
};

ostream& operator<<(ostream& out, Car& car);