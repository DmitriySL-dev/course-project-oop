#include "Carsalon.h"

InputCheck inp;
extern History hist;

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
		if ((*c).GetLogin() == login) {
			cout << "\nАккаунт с таким логином уже существует" << endl;
			return;
		}
	}
	Account a;
	pass = a.Encryption(pass);
	shared_ptr<Account> us(new User (name, surname, login, pass));
	accounts.push_back(us);
	cout << "\nДобавлено" << endl;

	hist.AddStrToHistory(login, "Зарегистрирован");
}

void Carsalon::AddAdmin()
{
	cout << "Введите имя, фамилию, логин, пароль: ";
	string name, surname, login, pass;

	cin >> name >> surname >> login >> pass;
	for (auto& c : accounts) {
		if ((*c).GetLogin() == login) {
			cout << "\nАккаунт с таким логином уже существует" << endl;
			return;
		}
	}
	Account a;
	pass = a.Encryption(pass);
	shared_ptr<Admin> ad(new Admin(name, surname, login, pass));
	//cout << &accounts[0]<<endl;
	accounts.push_back(ad);
	//cout << &accounts[0]<<endl;
	cout << "\nДобавлено" << endl;

	hist.AddStrToHistory(login, "Зарегистрирован");
}

void Carsalon::DeleteAcc(const string &lg)
{
	string login;

	cout << "Введите логин удаляемого аккаунта: ";
	cin >> login;
	if (login == lg) {
		cout << "\nОшибка" << endl;
		return;
	}
	for (size_t i = 0; i < accounts.size();++i) {
		if ((*accounts[i]).GetLogin() == login) {
			accounts.erase(accounts.begin() + i);
			for (size_t j = 0; j < cars.size();j++) {
				if (cars[j].GetUserId() == login) cars.erase(cars.begin()+j);
			}
			cout << "\nУспешно" << endl;
			hist.AddStrToHistory(login, "Удален");

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

	hist.AddStrToHistory("Админ", "Удален автомобиль: " + (*(cars.begin() + index - 1)).GetCarInfo());

	cars.erase(cars.begin() + index - 1);
	cout << "\nУспешно" << endl;
}

shared_ptr<Account> Carsalon::SignIn(bool& success) {
	string login, pass;
	Account a;
	cout << "Введите логин, пароль: ";
	cin >> login >> pass;
	for (auto& c : accounts) {
		if ((*c).GetLogin() == login && (*c).GetPass() == a.Encryption(pass)) return c;
	}
	cout << "\nАккаунт не найден"<<endl;
	success = false;
}

void Carsalon::BuyCar(shared_ptr<Account> acc)
{
	unsigned int index;
	if (cars.empty()) {
		cout << "Список пуст";
		return;
	}
	ShowCars();

	cout << "Введите номер автомобиля, который хотите купить: ";
	inp.GetValue<unsigned int>(index);
	while (index > cars.size()||index<1) {
		cout << "\nТакого номера нет, попытайтесь снова\n";
		inp.GetValue<unsigned int>(index);
	}
	unsigned int value = cars[index - 1].GetPrice();
	if ((*acc).Transaction(value)) {
		string UserID = cars[index - 1].GetUserId();
		for (auto& c : accounts) {
			if ((*c).GetLogin() == UserID) {
				(*c).PlusMoney(value);
				break;
			}
		}
		string NewUserID = (*acc).GetLogin();
		cars[index - 1].SetUserId(NewUserID);
		(*acc).AddCar(cars[index - 1]);

		hist.AddStrToHistory((*acc).GetLogin(), "Куплен автомобиль " + cars[index - 1].GetCarInfo());
		cars.erase(cars.begin() + index - 1);

		}
	
}

void Carsalon::SoldCar(shared_ptr<Account> acc)
{
	cout << "Введите марку, модель, кузов и цену автомобиля: ";
	string mk, md, body;
	unsigned int price;
	cin >> mk >> md >> body;
	inp.GetValue(price);
	Car car(mk, md, body, price, (*acc).GetLogin());
	cars.push_back(car);
	cout << "\nДобавлен для продажи" << endl;

	hist.AddStrToHistory((*acc).GetLogin(), "Добавлен для продажи автомобиль: " + car.GetCarInfo());
}

void Carsalon::SearchCar(shared_ptr<Account> acc)
{
}

void Carsalon::ShowCars() {
	unsigned int index = 0;
	if (cars.size() == 0) {
		cout << "\nСписок автомобилей пуст" << endl;
		return;
	}
	for (auto& c : cars) {
		cout << ++index << ". " << c.GetCarInfo() << endl;
	}
}

void Carsalon::ShowAccounts()
{
	cout << left << setw(12) << "\nИмя" <<setw(12)<< "Фамилия" <<setw(12)<< "Логин\n" << endl;
	for (auto& c : accounts) {
		cout << left << setw(12) << (*c).GetName()<<setw(12) << (*c).GetSurname()<<setw(12) << (*c).GetLogin() << endl;

		vector<Car> list = (*c).GetCarList();
		if (list.size()) {
			cout << "Автомобили:" << endl;
			int index = 1;
			for (auto& f : list) {
				cout << index++ << ". " << f.GetCarInfo()<<endl;
			}
		}
		cout << endl;

	}
}
