#include "Carsalon.h"

InputCheck inp;

Carsalon::Carsalon()
{
		File f;
		f.FromFile(accounts, "accounts.txt");
		f.FromFile(cars, "cars.txt");
}

void Carsalon::Record()
{
	File f;
	f.InFile(accounts, "accounts.txt");
	f.InFile(cars, "cars.txt");
}

void Carsalon::AddUser() {
	cout << "Введите имя, фамилию, логин, пароль: ";
	string name, surname, login, pass;
	cin >> name>>surname>>login>>pass;
	for (auto& c : accounts) {
		if (c.GetLogin() == login) {
			cout << "\nАккаунт с таким логином уже существует" << endl;
			return;
		}
	}
	Account a;
	pass = a.Encryption(pass);
	User us(name, surname, login, pass);
	accounts.push_back(us);
	cout << "\nДобавлено" << endl;
}

void Carsalon::AddAdmin()
{
	cout << "Введите имя, фамилию, логин, пароль: ";
	string name, surname, login, pass;
	cin >> name >> surname >> login >> pass;
	for (auto& c : accounts) {
		if (c.GetLogin() == login) {
			cout << "\nАккаунт с таким логином уже существует" << endl;
			return;
		}
	}
	Account a;
	pass = a.Encryption(pass);
	Admin ad(name, surname, login, pass);
	accounts.push_back(ad);
	cout << "\nДобавлено" << endl;
}

void Carsalon::DeleteAcc()
{
	string login;
	cout << "Введите логин удаляемого аккаунта: ";
	cin >> login;
	for (size_t i = 0; i < accounts.size();++i) {
		if (accounts[i].GetLogin() == login) {
			accounts.erase(accounts.begin() + i);
			cout << "\nУспешно" << endl;
			return;
		}
	}
	cout << "\nАккаунт с таким логином не существует" << endl;
}

void Carsalon::DeleteCar()
{
	unsigned int index = 0;
	if (cars.size() == 0) {
		cout << "\nСписок автомобилей пуст" << endl;
		return;
	}
	for (auto& c : cars) {
		cout << ++index << ". " << c << endl;
	}
	cout << "\nВыберите номер удаляемого автомобиля: ";
	inp.GetValue<unsigned int>(index);
	while (index > cars.size() || index < 1) {
		cout << "\nТакого номера нет, попытайтесь снова\n";
		inp.GetValue<unsigned int>(index);
	}
	cars.erase(cars.begin() + index - 1);
	cout << "\nУспешно" << endl;
}

Account* Carsalon::SignIn(bool& success) {
	string login, pass;
	Account a;
	cout << "Введите логин, пароль: ";
	cin >> login >> pass;
	for (auto& c : accounts) {
		if (c.GetLogin() == login && c.GetPass() == a.Encryption(pass)) return &c;
	}
	cout << "\nАккаунт не найден"<<endl;
	success = false;
	Account *acc=new Account;
	return acc;
}

void Carsalon::BuyCar(Account& acc)
{
	unsigned int index;
	ShowCars();
	cout << "Введите номер автомобиля, который хотите купить: ";
	inp.GetValue<unsigned int>(index);
	while (index > cars.size()||index<1) {
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
}

void Carsalon::ShowCars() {
	unsigned int index = 0;
	if (cars.size() == 0) {
		cout << "\nСписок автомобилей пуст" << endl;
		return;
	}
	for (auto& c : cars) {
		cout << ++index << ". " << c << endl;
	}
}

void Carsalon::ShowAccounts()
{
	cout << left << setw(12) << "\nИмя" <<setw(12)<< "Фамилия" <<setw(12)<< "Логин\n" << endl;
	for (auto& c : accounts) {
		cout << left << setw(12) << c.GetName()<<setw(12) << c.GetSurname()<<setw(12) << c.GetLogin() << endl;

		vector<Car> list = c.GetCarList();
		if (list.size()) {
			cout << "Автомобили:" << endl;
			int index = 1;
			for (auto& f : list) {
				cout << index++ << ". " << f<<endl;
			}
		}
		cout << endl;

	}
}
