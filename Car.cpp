#include "Car.h"

Car::Car():price(0) {}

Car::Car(string mk, string md, string b, unsigned int p,string userID)
{
		make = mk;
		model = md;
		body = b;
		price = p;
		this->userID = userID;
}

//string Car::GetMake()
//{
//	return make;
//}
//
//string Car::GetModel()
//{
//	return model;
//}
//
//string Car::GetBody()
//{
//	return body;
//}

string Car::GetUserId()
{
	return userID;
}

unsigned int Car::GetPrice()
{
	return price;
}

string Car::GetMake() const
{
	return make;
}

string Car::GetBody() const
{
	return body;
}

string Car::GetModel() const
{
	return model;
}

void Car::SetUserId(string& value)
{
	userID = value;
}

string Car::GetCarInfo()
{
	stringstream out;
	out << make << " " << model << " " << body << " " << price;
	return out.str();
}

ostream& operator<<(ostream& out, Car& car)
{
	out << car.make << " " << car.model << " " << car.body << " " << car.price<<" "<<car.userID;
	return out;
}

istream& operator>>(istream& out, Car& car) {
	out >> car.make >> car.model >> car.body >> car.price>>car.userID;
	return out;
}

bool operator<(Car& l, Car& r) {
	return tie(l.make, l.model, l.body, l.price) < tie(r.make, r.model, r.body, r.price);
}
