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
			{
				salon.Record();
				exit(0);
			}
			else {
				bool success = true;
				Account *temp = salon.SignIn(success);
				if (success)
				SelectMenu(*temp);
			}
			do {
				cout << "\nНажмите для продолжения" << endl;
			} while (!(_getch()));
		}


		system("cls");
	}

}

void Functions::SelectMenu(Account&temp)
{
	if (temp.GetStatus() == "Админ") AdminMenu(temp);
	else UserMenu(temp);
}

void Functions::UserMenu(Account& acc)
{


	vector<string> vec = {
		"Купить автомобиль",
		"Продать автомобиль",
		"Найти автомобиль",
		"Купленные автомобили",
		"Депозит",
		"Просмотреть баланс"
		,"Выйти из аккаунта" 
	};

	int str = 0;

	while (true) {
		system("cls");
		cout << "Текущий пользователь - " + acc.GetName() + " " + acc.GetSurname() << endl;
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
			else if (str == 3) acc.PrintCars();
			else if (str == 4) acc.Deposit();
			else if (str == 5) acc.CheckBalance();
			else if (str == 6) {
				system("cls"); Authorization();
			}
			do {
				cout << "\nНажмите для продолжения" << endl;
			} while (!(_getch()));
			break;
		default:
			break;

		}
	}

}

void Functions::AdminMenu(Account& acc)
{
	vector<string> vec = {
			"Просмотреть аккаунты",
			"Посмотреть все автомобили",
			"Добавить админа",
			"Удалить аккаунт",
			"Удалить автомобиль из продажи",
			"Редактировать свои персональные данные",
			"Выйти из аккаунта"
	};

	int str = 0;

	while (true) {
		system("cls");
		cout << "Текущий пользователь - " + acc.GetName() + " " + acc.GetSurname() << endl;
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
			if (str == 0) salon.ShowAccounts();
			else if (str == 1) salon.ShowCars();
			else if (str == 2) salon.AddAdmin();
			else if (str == 3) salon.DeleteAcc();
			else if (str == 4) salon.DeleteCar();
			else if (str == 5) acc.ChangePersonInfo(acc);
			else if (str == 6) {
				system("cls"); Authorization();
			}
			do {
				cout << "\nНажмите для продолжения" << endl;
			} while (!(_getch()));
			break;
		default:
			break;

		}
	}

}
