#include "Carsalon.h"

Carsalon::Carsalon()
{
		File f;
		f.FromFile(accounts, "accounts.txt");
}

void Carsalon::AddUser() {
	cout << "Введите имя, фамилию, логин, пароль: ";
	Account acc;
	cin >> acc;
	accounts.push_back(acc);
	cout << endl << "Добавлено" << endl;
}

Account& Carsalon::SignIn() {
	string login, pass;
	cout << "Введите логин, пароль: ";
	cin >> login >> pass;
	for (auto& c : accounts) {
		if (c.GetLogin() == login && c.GetPass() == pass) return c;
	}
}

void Carsalon::BuyCar(Account& acc)
{
	int index = 0;
	if (cars.size() == 0) {
		cout << "Список автомобилей пуст"<<endl;
		Sleep(1000);
		return;
	}
	for (auto& c : cars) {
		cout <<++index<<". "<<c<<endl;
	}
	cout << "Введите номер автомобиля, который хотите купить: ";
	cin >> index;
	unsigned int value = cars[index - 1].GetPrice();
	acc.Transaction(value);
	acc.AddCar(cars[index - 1]);
	cars.erase(cars.begin() + index-1);
	
}

void Carsalon::SoldCar(Account& acc)
{
	cout << "Введите марку, модель, кузов и цену автомобиля: ";
	string mk, md, body;
	unsigned int price;
	cin >> mk >> md >> body >> price;
	cars.push_back({ mk,md,body,price });
}

void Carsalon::SearchCar(Account&)
{
}
