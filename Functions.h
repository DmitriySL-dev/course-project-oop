#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include "Carsalon.h"
#include "Account.h"
#include "File.h"


using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace Functions {
	void Authorization();
	void SelectMenu(Account&);
	void UserMenu(Account&); 
	void AdminMenu(Account&);
}