#include "Car.h"

Car::Car() {}

Car::Car(string mk, string md, string b, string p)
{
		make = mk;
		model = md;
		body = b;
		price = p;
}

ostream& operator<<(ostream& out, Car& car)
{
	out << car.make << " " << car.model << " " << car.body << " " << car.price;
	return out;
}
