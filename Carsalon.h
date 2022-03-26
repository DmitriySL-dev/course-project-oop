#pragma once

#include "Account.h"
#include "File.h"
#include "Car.h"
#include <Windows.h>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

class Carsalon : public Car {
public:

	Carsalon();
	void AddUser();
	Account& SignIn();
	void BuyCar(Account&);
	void SoldCar(Account&);
	void SearchCar(Account&);

private:
	vector<Account> accounts;
	vector<Car> cars;
};