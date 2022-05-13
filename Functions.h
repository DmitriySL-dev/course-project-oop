#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include <memory>

#include "Carsalon.h"
#include "Account.h"
#include "File.h"


using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace Functions {  //Пространство имен функций
	void Authorization();
	void SelectMenu(shared_ptr<Account>);
	void UserMenu(shared_ptr<Account>); 
	void AdminMenu(shared_ptr<Account>);
}