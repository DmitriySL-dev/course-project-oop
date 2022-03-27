#pragma once

#include <Windows.h>
#include <vector>
#include <iomanip>

#include "InputCheck.h"
#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "File.h"
#include "Car.h"

using std::vector;
using std::cin;
using std::cout;

class Carsalon : public Car {
public:

	Carsalon();
	void Record();

							//USER FUCTIONALITY
	void AddUser();			
	Account* SignIn(bool&);

	void BuyCar(Account&);
	void SoldCar(Account&);
	void SearchCar(Account&);
	void ShowCars();

							//ADMIN FUNCTIONALITY
	void AddAdmin();		

	void DeleteAcc();
	void DeleteCar();

	void ShowAccounts();
private:
	vector<Account> accounts;
	vector<Car> cars;
};