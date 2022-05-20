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
	cout << "������� ���, �������, �����: ";
	string name, surname, login, pass="";
	cin >> name >> surname >> login;
	system("cls");
	cout << "������� ������: ";
	while (true) {
		char symb = _getch();
		if (symb == 13) break;
		if (symb == 32) continue;
		if (symb == 8 && !pass.empty()) {
			system("cls");
			cout << "������� ������: ";
			for (int i = 0; i < pass.length() - 1;i++) {
				cout << "*";
			}
			pass.erase(pass.end() - 1);
		}
		else  if(symb!=8) {
			cout << "*";
			pass += symb;
		}
	}
	
	for (auto& c : accounts) {
		if (c->GetLogin() == login) {
			cout << "\n������� � ����� ������� ��� ����������" << endl;
			return;
		}
	}
	Account a;
	pass = a.Encryption(pass);
	shared_ptr<Account> us;
	try {
		us = make_shared<Account>(User(name, surname, login, pass));
	}
	catch (...) {
		cout << "������ ��������� ������"<<endl;
		return;
	}
	accounts.push_back(us);
	cout << "\n���������" << endl;

	hist.AddStrToHistory(login, "���������������");
}

void Carsalon::AddAdmin()
{
	cout << "������� ���, �������, �����, ������: ";
	string name, surname, login, pass;

	cin >> name >> surname >> login >> pass;
	for (auto& c : accounts) {
		if (c->GetLogin() == login) {
			cout << "\n������� � ����� ������� ��� ����������" << endl;
			return;
		}
	}
	Account a;
	pass = a.Encryption(pass);
	shared_ptr<Admin> ad(new Admin(name, surname, login, pass));
	//cout << &accounts[0]<<endl;
	accounts.push_back(ad);
	//cout << &accounts[0]<<endl;
	cout << "\n���������" << endl;

	hist.AddStrToHistory(login, "���������������");
}

void Carsalon::DeleteAcc(const string &lg)
{
	string login;

	cout << "������� ����� ���������� ��������: ";
	cin >> login;
	if (login == lg) {
		cout << "\n������" << endl;
		return;
	}
	for (size_t i = 0; i < accounts.size();++i) {
		if (accounts[i]->GetLogin() == login) {
			accounts.erase(accounts.begin() + i);
			for (size_t j = 0; j < cars.size();j++) {
				if (cars[j].GetUserId() == login) cars.erase(cars.begin()+j);
			}
			cout << "\n�������" << endl;
			hist.AddStrToHistory(login, "������");

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

	hist.AddStrToHistory("�����", "������ ����������: " + (cars.begin() + index - 1)->GetCarInfo());

	cars.erase(cars.begin() + index - 1);
	cout << "\n�������" << endl;
}

shared_ptr<Account> Carsalon::SignIn(bool& success) {
	string login, pass = "";
	Account a;
	cout << "������� ����� ";
	cin >> login;
	system("cls");
	cout << "������� ������: ";
	while (true) {
		char symb = _getch();
		if (symb == 13) break;
		if (symb == 32) continue;
		if (symb == 8 && !pass.empty()) {
			system("cls");
			cout << "������� ������: ";
			for (int i = 0; i < pass.length() - 1; i++) {
				cout << "*";
			}
			pass.erase(pass.end() - 1);
		}
		else  if (symb != 8) {
			cout << "*";
			pass += symb;
		}
	}

	for (auto& c : accounts) {
		if (c->GetLogin() == login && c->GetPass() == a.Encryption(pass)) return c;
	}
	cout << "\n������� �� ������" << endl;
	success = false;
}

void Carsalon::BuyCar(shared_ptr<Account> &acc)
{
	unsigned int index;
	if (cars.empty()) {
		cout << "������ ����";
		return;
	}
	ShowCars();

	cout << "������� ����� ����������, ������� ������ ������: ";
	inp.GetValue<unsigned int>(index);
	while (index > cars.size()||index<1) {
		cout << "\n������ ������ ���, ����������� �����\n";
		inp.GetValue<unsigned int>(index);
	}
	unsigned int value = cars[index - 1].GetPrice();
	if (acc->Transaction(value)) {
		string UserID = cars[index - 1].GetUserId();
		for (auto& c : accounts) {
			if (c->GetLogin() == UserID) {
				c->PlusMoney(value);
				break;
			}
		}
		string NewUserID = acc->GetLogin();
		cars[index - 1].SetUserId(NewUserID);
		acc->AddCar(cars[index - 1]);

		hist.AddStrToHistory(acc->GetLogin(), "������ ���������� " + cars[index - 1].GetCarInfo());
		cars.erase(cars.begin() + index - 1);

		}
	
}

void Carsalon::SoldCar(shared_ptr<Account> &acc)
{
	cout << "������� �����, ������, ����� � ���� ����������: ";
	string mk, md, body;
	unsigned int price;
	cin >> mk >> md >> body;
	inp.GetValue(price);
	Car car(mk, md, body, price, acc->GetLogin());
	cars.push_back(car);
	cout << "\n�������� ��� �������" << endl;

	hist.AddStrToHistory(acc->GetLogin(), "�������� ��� ������� ����������: " + car.GetCarInfo());
}

void Carsalon::SearchCar(shared_ptr<Account> &acc) //����� �����������
{
	if (cars.size() == 0) {
		cout << "\n������ ����������� ����" << endl;
		return;
	}
	system("cls");
	cout <<
		"1. �����\n"
		"2. ������\n"
		"3. �����\n"
		"4. ����\n";
	
	int field=0;
	while (field < 1 || field>4) { //�������� �� ����
		cout << "������� ����, �� �������� ���������� �����: ";
		inp.GetValue(field);
		if (field < 1 || field>4) cout << "�������� ����" << endl;
	}

	bool founded = 0;  //���� ��������� ������

	switch (field) {
	case 1:
	{
		string make;
		int idx = 1;
		cout << "������� ������� �����: ";
		cin >> make;
		for (auto& c : cars) {
			if (c.GetMake() == make) {
				founded = 1;
				cout << idx++ << ". " << c.GetCarInfo() << endl;
			}
		}
		break;
	}
	case 2:
	{
		string model;
		int idx = 1;
		cout << "������� ������� ������: ";
		cin >> model;
		for (auto& c : cars) {
			if (c.GetModel() == model) {
				founded = 1;
				cout << idx++ << ". " << c.GetCarInfo() << endl;
			}
		}
		break;
	}
	case 3:
	{
		string body;
		int idx = 1;
		cout << "������� ������� �����: ";
		cin >> body;
		for (auto& c : cars) {
			if (c.GetBody() == body) {
				founded = 1;
				cout << idx++ << ". " << c.GetCarInfo() << endl;
			}
		}
		break;
	}
	case 4:
	{
		unsigned int price_l,price_r;
		int idx = 1;
		cout << "������� ����������� �������� ����: ";
		inp.GetValue(price_l);
		cout << "������� ������������ �������� ����: ";
		inp.GetValue(price_r);
		for (auto& c : cars) {
			if (c.GetPrice() >=price_l && c.GetPrice()<=price_r) {
				founded = 1;
				cout << idx++ << ". " << c.GetCarInfo() << endl;
			}
		}
		break;
	}
	}
	if (!founded) {
		cout << "�� �������" << endl;
	}
}

void Carsalon::SortCars(shared_ptr<Account> &acc)
{
	if (cars.size() == 0) {
		cout << "\n������ ����������� ����" << endl;
		return;
	}
	sort(cars.begin(), cars.end());
	hist.AddStrToHistory(acc->GetLogin(), "������������ ������ �����������");
}


void Carsalon::ShowCars() {
	unsigned int index = 0;
	if (cars.size() == 0) {
		cout << "\n������ ����������� ����" << endl;
		return;
	}
	for (auto& c : cars) {
		cout << ++index << ". " << c.GetCarInfo() << endl;
	}
}

void Carsalon::ShowAccounts()
{
	cout << left << setw(12) << "\n���" <<setw(12)<< "�������" <<setw(12)<< "�����\n" << endl;
	for (auto& c : accounts) {
		cout << left << setw(12) << c->GetName()<<setw(12) << c->GetSurname()<<setw(12) << c->GetLogin() << endl;

		vector<Car> list = c->GetCarList();
		if (list.size()) {
			cout << "����������:" << endl;
			int index = 1;
			for (auto& f : list) {
				cout << index++ << ". " << f.GetCarInfo()<<endl;
			}
			cout << endl;
		}
		

	}
}
