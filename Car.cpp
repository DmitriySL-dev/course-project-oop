#include "Car.h"

Car::Car() {}

Car::Car(string mk, string md, string b, unsigned int p)
{
		make = mk;
		model = md;
		body = b;
		price = p;
}

unsigned int Car::GetPrice()
{
	return price;
}

ostream& operator<<(ostream& out, Car& car)
{
	out << car.make << " " << car.model << " " << car.body << " " << car.price;
	return out;
}

istream& operator>>(istream& out, Car& car) {
	out >> car.make >> car.model >> car.body >> car.price;
	return out;
}
