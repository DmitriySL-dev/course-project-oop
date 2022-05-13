#pragma once

#include <iostream>
#include <sstream>

using namespace std;

class Car { //Класс автомобиля
public:
	Car();
	Car(string mk, string md, string b, unsigned int p,string userID);
	
	string GetUserId();
	unsigned int GetPrice();

	void SetUserId(string &value);
	string GetCarInfo();

	friend ostream& operator<<(ostream& out, Car& car);
	friend istream& operator>>(istream& out, Car& car);

protected:
	string make;
	string model;
	string body;
	string userID;
	unsigned int price;
};