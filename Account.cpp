#include "Account.h"

extern InputCheck inp;

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

void Account::SetStatus()
{
    status = "";
}

string Account::Encryption(string&inp)
{
    string outp = "";
    for (auto& c : inp) {
        outp += c ^ 2;
    }
    return outp;
}

void Account::Deposit()
{
    unsigned int cash;
    cout << "Введите сумму: ";
    inp.GetValue<unsigned int>(cash);
    money += cash;
    cout << "\nУспешно" << endl;
}

void Account::CheckBalance() const
{
    cout << "\nТекущий баланс - " << money << endl;
}

void Account::AddCar(Car& car) {
    list.push_back(car);
}

void Account::GetCars()
{
    int index = 0;
    if (!list.size()) {
        cout << "\nПусто\n";
        return;
    }
        for (auto& c : list) {
        cout << ++index<<". " << c << endl;
    }

}

bool Account::Transaction(unsigned int& value)
{
    if (value > money) {
        cout << "\nНе хватает денег" << endl; return 0;
    }
    else {
        money -= value;
        cout << "\nУспешно" << endl;
        return 1;
    }
}

istream& operator>>(istream& out, Account& acc) {
    out >> acc.name >> acc.surname >> acc.login >> acc.pass>>acc.money>>acc.status;
    acc.list.clear();
    string buf;
    out.ignore(1);
    getline(out, buf);
    while (buf != "/"&& !out.eof()&&buf!="") {
        stringstream sstr(buf);
        Car c;
        //out >> c;
        sstr >> c;
        acc.list.push_back(c);
        getline(out, buf);
    }
    return out;
}

ostream& operator<<(ostream& out, Account& acc) {
    out << acc.name << " " << acc.surname << " " << acc.login << " " << acc.pass<<" "<<acc.money<<" "<<acc.status<<endl;
    for (auto& c : acc.list) {
        out << c<<endl;
    }
    out<<"/";
    return out;
}
