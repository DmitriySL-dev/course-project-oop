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
    Account():money(0) {}

    string GetPass() const;
    string GetLogin() const;
    string GetName() const;
    string GetSurname() const;
    string GetStatus() const;
    vector<Car> GetCarList()const;

    string Encryption(string&);
    virtual void SetStatus();

    void ChangePersonInfo(Account&);
    void ChangeName();
    void ChangeSurname();
    void ChangeLogin();
    void ChangePass();

    void Deposit();
    void CheckBalance() const;
    void AddCar(Car&);
    void PrintCars();
    bool Transaction(unsigned int&);

    friend istream& operator>>(istream& out, Account& acc);
    friend ostream& operator<<(ostream& out, Account& acc);
protected:
    string name;
    string surname;
    string pass;
    string login;
   // string number;
    string status;
    unsigned int money;
    vector<Car> list;
};