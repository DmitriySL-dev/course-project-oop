#include "Functions.h"

Carsalon salon;

void Functions::Authorization()
{
	vector<string> vec = { "Регистрация","Вход","Выход" };
	int str = 0;


	while (true) {

		for (size_t i = 0; i < vec.size(); ++i) {
			if (i == str)
				cout << "> " + vec[i] << endl;
			else
				cout << vec[i] << endl;
		}

		switch (_getch()) {
		case 72:			//up
			--str;
			if (str == -1) str = 2;
			break;
		case 80:			//down
			++str;
			if (str == 3) str = 0;
			break;
		case 13:			//enter
			if (str == 0)
				salon.AddUser();
			else if (str == 2)

				exit(0);
			else {
				Account temp = salon.SignIn();
				SelectMenu(temp);
			}
		}


		system("cls");
	}

}

void Functions::SelectMenu(Account&temp)
{
	if (temp.GetStatus() == "Admin") AdminMenu(temp);
	else UserMenu(temp);
}

void Functions::UserMenu(Account& acc)
{
	

	vector<string> vec = { "Купить автомобиль","Продать автомобиль", "Найти автомобиль","Купленные автомобили","Депозит","Просмотреть баланс","Выйти из аккаунта" };
	int str = 0;

	while (true) {
		system("cls");
		cout << "Текущий пользователь - " + acc.GetName() + " " + acc.GetSurname()<<endl;
		for (size_t i = 0; i < vec.size(); ++i) {
			if (str == i) cout << "> " + vec[i] << endl;
			else cout << vec[i] << endl;
		}

		switch (_getch()) {
		case 72:
			--str;
			if (str == -1) str = 6;
			break;
		case 80:
			++str;
			if (str == 7) str = 0;
			break;
		case 13:
			if (str == 0) salon.BuyCar(acc);
			else if (str == 1) salon.SoldCar(acc);
			else if (str == 2) salon.SearchCar(acc);
			else if (str == 3) acc.GetCars();
			else if (str == 4) acc.Deposit();
			else if (str == 4) acc.CheckBalance();
			else Authorization();
			break;
		default:
			break;

		}
	}

}

void Functions::AdminMenu(Account& acc)
{
	cout <<
		"1."
		"2."
		"3.";
}
