#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <conio.h>
#include "Car.h"
#include "InputCheck.h"

using std::string;
using std::istream;
using std::ostream;
using std::vector;

class Account {
public:
    Account(const string &name1, const string &surname1, const string &login1, const string &pass1);
    Account() {}

    string GetPass() const;
    string GetLogin() const;
    string GetName() const;
    string GetSurname() const;
    string GetStatus() const;
    void Deposit();
    void CheckBalance() const;
    void AddCar(Car&);
    void GetCars();
    bool Transaction(unsigned int&);

    friend istream& operator>>(istream& out, Account& acc);
    friend ostream& operator<<(ostream& out, Account& acc);
private:
    string name;
    string surname;
    string pass;
    string login;
   // string number;
    string status;
    unsigned int money=0;
    vector<Car> list;
};