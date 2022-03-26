#include "Carsalon.h"

InputCheck inp;

Carsalon::Carsalon()
{
		File f;
		f.FromFile(accounts, "accounts.txt");
}

void Carsalon::AddUser() {
	cout << "������� ���, �������, �����, ������: ";
	Account acc;
	cin >> acc;
	accounts.push_back(acc);
	cout << "\n���������" << endl;
}

Account& Carsalon::SignIn(bool& success) {
	string login, pass;
	cout << "������� �����, ������: ";
	cin >> login >> pass;
	for (auto& c : accounts) {
		if (c.GetLogin() == login && c.GetPass() == pass) return c;
	}
	cout << "\n������� �� ������"<<endl;
	success = false;
	Account *acc=new Account;
	return *acc;
}

void Carsalon::BuyCar(Account& acc)
{
	unsigned int index = 0;
	if (cars.size() == 0) {
		cout << "\n������ ����������� ����"<<endl;
		return;
	}
	for (auto& c : cars) {
		cout <<++index<<". "<<c<<endl;
	}
	cout << "������� ����� ����������, ������� ������ ������: ";
	inp.GetValue<unsigned int>(index);
	while (index > cars.size()) {
		cout << "\n������ ������ ���, ����������� �����\n";
		inp.GetValue<unsigned int>(index);
	}
	unsigned int value = cars[index - 1].GetPrice();
	if (acc.Transaction(value)) {
		acc.AddCar(cars[index - 1]);
		cars.erase(cars.begin() + index - 1);
	}
	
}

void Carsalon::SoldCar(Account& acc)
{
	cout << "������� �����, ������, ����� � ���� ����������: ";
	string mk, md, body;
	unsigned int price;
	cin >> mk >> md >> body;
	inp.GetValue(price);
	cars.push_back({ mk,md,body,price });
	cout << "\n�������� ��� �������" << endl;
}

void Carsalon::SearchCar(Account&)
{
	f

		fdsfsdfsdfsdfsd
}
