#pragma once

#include <iostream>
#include <sstream>
#include <tuple>

using namespace std;

class Car { //Класс автомобиля
public:
	Car();
	Car(string mk, string md, string b, unsigned int p,string userID);
	
	string GetUserId();
	unsigned int GetPrice();
	string GetMake() const;
	string GetBody() const;
	string GetModel() const;

	void SetUserId(string &value);
	string GetCarInfo();


	friend ostream& operator<<(ostream& out, Car& car);
	friend istream& operator>>(istream& out, Car& car);

	friend bool operator<(Car& l, Car& r);
protected:
	string make;
	string model;
	string body;
	string userID;
	unsigned int price;
};