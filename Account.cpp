#include "Account.h"

Account::Account(const string &name1, const string &surname1, const string &login1, const string &pass1)
{
    name = name1;
    surname = surname1;
    login = login1;
    pass = pass1;
}

string Account::GetPass() const
{
    return pass;
}

string Account::GetLogin() const
{
    return login;
}

string Account::GetName() const
{
    return name;
}

string Account::GetSurname() const
{
    return surname;
}

string Account::GetStatus() const
{
    return status;
}

void Account::Deposit()
{
    unsigned int cash;
    cout << "Введите сумму: ";
    cin >> cash;
    money += cash;
}

void Account::CheckBalance() const
{
    cout << "Текущий баланс - " << money << endl;
    do {
        cout << "Нажмите для продолжения";
    } while (!_getch());
}

void Account::AddCar(Car& car) {
    list.push_back(car);
}

void Account::GetCars()
{
    int index = 0;
    for (auto& c : list) {
        cout << ++index<<". " << c << endl;
    }

    do { cout << "Нажмите для продолжения" << endl; 
    } while (!_getch());
}

istream& operator>>(istream& out, Account& acc) {
    out >> acc.name >> acc.surname >> acc.login >> acc.pass;
    return out;
}

ostream& operator<<(ostream& out, Account& acc) {
    out << acc.name << " " << acc.surname << " " << acc.login << " " << acc.pass;
    return out;
}
