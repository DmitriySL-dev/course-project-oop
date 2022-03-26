#pragma once

#include "Account.h"
#include "File.h"
#include "Car.h"
#include <Windows.h>
#include <vector>
#include "InputCheck.h"

using std::vector;
using std::cin;
using std::cout;

class Carsalon : public Car {
public:

	Carsalon();
	void Record();
	void AddUser();
	Account* SignIn(bool&);
	void BuyCar(Account&);
	void SoldCar(Account&);
	void SearchCar(Account&);

private:
	vector<Account> accounts;
	vector<Car> cars;
};