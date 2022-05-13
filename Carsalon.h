#pragma once

#include <Windows.h>
#include <vector>
#include <iomanip>
#include <memory>

#include "InputCheck.h"
#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "File.h"
#include "Car.h"
#include "History.h"

using std::vector;
using std::cin;
using std::cout;

class Carsalon : public Car { //Класс автосалона
public:

	Carsalon();
	void Record();

							//Функционал пользователя
	void AddUser();			
	shared_ptr<Account> SignIn(bool&);

	void BuyCar(shared_ptr<Account>);
	void SoldCar(shared_ptr<Account>);
	void SearchCar(shared_ptr<Account>);
	void ShowCars();

							//Функционал админа
	void AddAdmin();		

	void DeleteAcc(const string &cc);
	void DeleteCar();

	void ShowAccounts();
private:
	vector<shared_ptr<Account>> accounts;
	vector<Car> cars;
};