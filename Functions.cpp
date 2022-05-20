#include "Functions.h"

static Carsalon salon;
History hist;

void Functions::SetColor(int back, int text)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((back << 4) | text));
}

void Functions::Authorization() //������� �����������
{
	vector<string> vec = { "�����������","����","�����" };
	int str = 0;


	while (true) {

		for (size_t i = 0; i < vec.size(); ++i) {
			if (i == str)
			{
				SetColor(0, 4);
				cout << "> " + vec[i] << endl;
				SetColor(0, 15);
			}
			else
				cout << vec[i] << endl;
		}

		switch (_getch()) {
		case 72:			//������� ������� �����
			--str;
			if (str == -1) str = 2;
			break;
		case 80:			//������� ������� ����
			++str;
			if (str == 3) str = 0;
			break;
		case 13:			//������� ������� enter
			if (str == 0)
				salon.AddUser();
			else if (str == 2)
			{
				salon.Record();
				exit(0);
			}
			else {
				bool success = true;
				shared_ptr<Account> temp = salon.SignIn(success); //��������� ��������� �� ������, � ������� ����� ��������
				if (success)
				SelectMenu(temp); //����� ���� � ������������ �� ��������
			}
			do {
				cout << "\n������� ��� �����������" << endl;
			} while (!(_getch()));
		}


		system("cls");
	}

}

void Functions::SelectMenu(shared_ptr<Account> temp)
{
	if (temp->GetStatus() == "�����") AdminMenu(temp);
	else UserMenu(temp);
}

void Functions::UserMenu(shared_ptr<Account> acc)
{


	vector<string> vec = {
		"������ ����������",
		"������� ����������",
		"����� ����������",
		"��������� ����������",
		"�������",
		"����������� ������",
		"������������� ������������ ������",
		"����� �� ��������" 
	};

	int str = 0;

	while (true) {
		system("cls");
		cout << "������� ������������ - " + acc->GetName() + " " + acc->GetSurname() << endl;
		for (size_t i = 0; i < vec.size(); ++i) {
			if (str == i)
			{
				SetColor(0, 4);
				cout << "> " + vec[i] << endl;
				SetColor(0, 15);
			}
			else cout << vec[i] << endl;
		}

		switch (_getch()) {
		case 72:
			--str;
			if (str == -1) str = 7;
			break;
		case 80:
			++str;
			if (str == 8) str = 0;
			break;
		case 13:
			if (str == 0) salon.BuyCar(acc);
			else if (str == 1) salon.SoldCar(acc);
			else if (str == 2) salon.SearchCar(acc);
			else if (str == 3) acc->PrintCars();
			else if (str == 4) acc->Deposit();
			else if (str == 5) acc->CheckBalance();
			else if (str == 6) acc->ChangePersonInfo();
			else if (str == 7) {
				system("cls"); Authorization();
			}
			do {
				cout << "\n������� ��� �����������" << endl;
			} while (!(_getch()));
			break;
		default:
			break;

		}
	}

}

void Functions::AdminMenu(shared_ptr<Account> acc)
{
	vector<string> vec = {
			"����������� ��������",
			"���������� ��� ����������",
			"�������� ������",
			"������� �������",
			"������� ���������� �� �������",
			"������������� ��� ����������",
			"������������� ���� ������������ ������",
			"�������� ������� ��������",
			"����� �� ��������"
	};

	int str = 0;

	while (true) {
		system("cls");
		//cout << &acc<<endl;
		cout << "������� ������������ - " + acc->GetName() + " " + acc->GetSurname() << endl;
		for (size_t i = 0; i < vec.size(); ++i) {
			if (str == i)
			{
				SetColor(0, 4);
				cout << "> " + vec[i] << endl;
				SetColor(0, 15);
			}
			else cout << vec[i] << endl;
		}


		switch (_getch()) {
		case 72:
			--str;
			if (str == -1) str = 8;
			break;
		case 80:
			++str;
			if (str == 9) str = 0;
			break;
		case 13:
			if (str == 0) salon.ShowAccounts();
			else if (str == 1) salon.ShowCars();
			else if (str == 2)  salon.AddAdmin();
			else if (str == 3) salon.DeleteAcc(acc->GetLogin());
			else if (str == 4) salon.DeleteCar();
			else if (str == 5) salon.SortCars(acc);
			else if (str == 6) acc->ChangePersonInfo();
			else if (str == 7) hist.WatchHistory();
			else if (str == 8) {
				system("cls"); Authorization();
			}
			do {
				cout << "\n������� ��� �����������" << endl;
			} while (!(_getch()));
			break;
		default:
			break;

		}
	}

}
