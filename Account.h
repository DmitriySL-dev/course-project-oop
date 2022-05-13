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

class Account { //Класс аккаунта
public:
    Account(const string &name1, const string &surname1, const string &login1, const string &pass1);
    Account():money(0) {}

    const string& GetPass() const;  //Геттеры класса
    const string& GetLogin() const;
    const string& GetName() const;
    const string& GetSurname() const;
    const string& GetStatus() const;
    vector<Car> GetCarList()const;

    string Encryption(string&); //Функция шифровки/дешифровки пароля
    virtual void SetStatus();  //Виртуальная функция

    void ChangePersonInfo();  //Функции изменения персональных данных
    void ChangeName();
    void ChangeSurname();
    void ChangeLogin();
    void ChangePass();

    void Deposit();
    void CheckBalance() const;
    void AddCar(Car&);
    void PrintCars();
    bool Transaction(unsigned int&);
    void PlusMoney(unsigned int& value);

    friend istream& operator>>(istream& out, Account& acc);
    friend ostream& operator<<(ostream& out, Account& acc);
protected:
    string name;
    string surname;
    string pass;
    string login;
    string status;
    unsigned int money;
    vector<Car> list;
};