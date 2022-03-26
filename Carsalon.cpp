#include "Carsalon.h"

InputCheck inp;

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
	cout << "\nДобавлено" << endl;
}

Account& Carsalon::SignIn(bool& success) {
	string login, pass;
	cout << "Введите логин, пароль: ";
	cin >> login >> pass;
	for (auto& c : accounts) {
		if (c.GetLogin() == login && c.GetPass() == pass) return c;
	}
	cout << "\nАккаунт не найден"<<endl;
	success = false;
	Account *acc=new Account;
	return *acc;
}

void Carsalon::BuyCar(Account& acc)
{
	unsigned int index = 0;
	if (cars.size() == 0) {
		cout << "\nСписок автомобилей пуст"<<endl;
		return;
	}
	for (auto& c : cars) {
		cout <<++index<<". "<<c<<endl;
	}
	cout << "Введите номер автомобиля, который хотите купить: ";
	inp.GetValue<unsigned int>(index);
	while (index > cars.size()) {
		cout << "\nТакого номера нет, попытайтесь снова\n";
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
	cout << "Введите марку, модель, кузов и цену автомобиля: ";
	string mk, md, body;
	unsigned int price;
	cin >> mk >> md >> body;
	inp.GetValue(price);
	cars.push_back({ mk,md,body,price });
	cout << "\nДобавлен для продажи" << endl;
}

void Carsalon::SearchCar(Account&)
{
	f

		fdsfsdfsdfsdfsd
}
