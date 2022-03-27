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
	cout << "������� ���, �������, �����, ������: ";
	string name, surname, login, pass;
	cin >> name>>surname>>login>>pass;
	for (auto& c : accounts) {
		if (c.GetLogin() == login) {
			cout << "\n������� � ����� ������� ��� ����������" << endl;
			return;
		}
	}
	Account a;
	pass = a.Encryption(pass);
	User us(name, surname, login, pass);
	accounts.push_back(us);
	cout << "\n���������" << endl;
}

void Carsalon::AddAdmin()
{
	cout << "������� ���, �������, �����, ������: ";
	string name, surname, login, pass;
	cin >> name >> surname >> login >> pass;
	for (auto& c : accounts) {
		if (c.GetLogin() == login) {
			cout << "\n������� � ����� ������� ��� ����������" << endl;
			return;
		}
	}
	Account a;
	pass = a.Encryption(pass);
	Admin ad(name, surname, login, pass);
	accounts.push_back(ad);
	cout << "\n���������" << endl;
}

void Carsalon::DeleteAcc()
{
	string login;
	cout << "������� ����� ���������� ��������: ";
	cin >> login;
	for (size_t i = 0; i < accounts.size();++i) {
		if (accounts[i].GetLogin() == login) {
			accounts.erase(accounts.begin() + i);
			cout << "\n�������" << endl;
			return;
		}
	}
	cout << "\n������� � ����� ������� �� ����������" << endl;
}

void Carsalon::DeleteCar()
{
	unsigned int index = 0;
	if (cars.size() == 0) {
		cout << "\n������ ����������� ����" << endl;
		return;
	}
	for (auto& c : cars) {
		cout << ++index << ". " << c << endl;
	}
	cout << "\n�������� ����� ���������� ����������: ";
	inp.GetValue<unsigned int>(index);
	while (index > cars.size() || index < 1) {
		cout << "\n������ ������ ���, ����������� �����\n";
		inp.GetValue<unsigned int>(index);
	}
	cars.erase(cars.begin() + index - 1);
	cout << "\n�������" << endl;
}

Account* Carsalon::SignIn(bool& success) {
	string login, pass;
	Account a;
	cout << "������� �����, ������: ";
	cin >> login >> pass;
	for (auto& c : accounts) {
		if (c.GetLogin() == login && c.GetPass() == a.Encryption(pass)) return &c;
	}
	cout << "\n������� �� ������"<<endl;
	success = false;
	Account *acc=new Account;
	return acc;
}

void Carsalon::BuyCar(Account& acc)
{
	unsigned int index;
	ShowCars();
	cout << "������� ����� ����������, ������� ������ ������: ";
	inp.GetValue<unsigned int>(index);
	while (index > cars.size()||index<1) {
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
}

void Carsalon::ShowCars() {
	unsigned int index = 0;
	if (cars.size() == 0) {
		cout << "\n������ ����������� ����" << endl;
		return;
	}
	for (auto& c : cars) {
		cout << ++index << ". " << c << endl;
	}
}

void Carsalon::ShowAccounts()
{
	cout << left << setw(12) << "\n���" <<setw(12)<< "�������" <<setw(12)<< "�����\n" << endl;
	for (auto& c : accounts) {
		cout << left << setw(12) << c.GetName()<<setw(12) << c.GetSurname()<<setw(12) << c.GetLogin() << endl;

		vector<Car> list = c.GetCarList();
		if (list.size()) {
			cout << "����������:" << endl;
			int index = 1;
			for (auto& f : list) {
				cout << index++ << ". " << f<<endl;
			}
		}
		cout << endl;

	}
}
