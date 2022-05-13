#include "Account.h"

extern InputCheck inp;

Account::Account(const string &name1, const string &surname1, const string &login1, const string &pass1)
{
    name = name1;
    surname = surname1;
    login = login1;
    pass = pass1;
}

const string& Account::GetPass() const
{
    return pass;
}

const string& Account::GetLogin() const
{
    return login;
}

const string& Account::GetName() const
{
    return name;
}

const string& Account::GetSurname() const
{
    return surname;
}

const string& Account::GetStatus() const
{
    return status;
}

vector<Car> Account::GetCarList() const
{
    return list;
}

void Account::SetStatus()
{
    status = "";
}

void Account::ChangePersonInfo()
{
    int str = 0;

    while (true) {
        system("cls");
        vector<string> vec = {
            "��� - " + name,
            "������� - " + surname,
            "����� - " + login,
            "������ - *******",
            "����� �� ���� ��������������"
        };
        cout << "�������� ������������� ��������: "<< endl;
        for (size_t i = 0; i < vec.size(); ++i) {
            if (str == i) cout << "> " + vec[i] << endl;
            else cout << vec[i] << endl;
        }

        switch (_getch()) {
        case 72:
            --str;
            if (str == -1) str = 4;
            break;
        case 80:
            ++str;
            if (str == 5) str = 0;
            break;
        case 13:
            if (str == 0) ChangeName();
            else if (str == 1) ChangeSurname();
            else if (str == 2) ChangeLogin();
            else if (str == 3) ChangePass();
            else if (str == 4) {
                system("cls"); return;
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

void Account::ChangeName()
{
    string name;
    cout << "������� ����� ���: ";
    cin >> name;
    this->name = name;
    cout << "\n�������" << endl;
}

void Account::ChangeSurname()
{
    string surname;
    cout << "������� ����� �������: ";
    cin >> surname;
    this->surname = surname;
    cout << "\n�������" << endl;
}

void Account::ChangeLogin() {
    string login;
    cout << "������� ����� �����: ";
    cin >> login;
    this->login = login;
    cout << "\n�������" << endl;
}

void Account::ChangePass() {
    string old_pass, new_pass;
    cout << "������� ������ ������: ";
    cin >> old_pass;
    if (Encryption(old_pass) == pass) {
        cout << "������� ����� ������: ";
        cin >> new_pass;
        this->pass = Encryption(new_pass);
        cout << "\n�������" << endl;
    }
    else {
        cout << "�������� ������" << endl;
    }

}

string Account::Encryption(string&inp) //������� ����������
{
    string outp = "";
    for (auto& c : inp) {
        outp += c ^ 2; //���������� XOR ��������
    }
    return outp;
}

void Account::Deposit()
{
    unsigned int cash;
    cout << "������� �����: ";
    inp.GetValue<unsigned int>(cash);
    money += cash;
    cout << "\n�������" << endl;
}

void Account::CheckBalance() const
{
    cout << "\n������� ������ - " << money << endl;
}

void Account::AddCar(Car& car) {
    list.push_back(car);
}

void Account::PrintCars()
{
    int index = 0;
    if (!list.size()) {
        cout << "\n�����\n";
        return;
    }
    for (auto& c : list) {
        cout << ++index << ". " << c.GetCarInfo() << endl;
    }

}

bool Account::Transaction(unsigned int& value)
{
    if (value > money) {
        cout << "\n�� ������� �����" << endl; return 0;
    }
    else {
        money -= value;
        cout << "\n�������" << endl;
        return 1;
    }
}

void Account::PlusMoney(unsigned int& value)
{
    money += value;
}

istream& operator>>(istream& out, Account& acc) {
    out >> acc.name >> acc.surname >> acc.login >> acc.pass>>acc.money>>acc.status;
    string buf;
    out.ignore(1);
    getline(out, buf);

    while (buf != "/"&& !out.eof()&&buf!="") {
        stringstream sstr(buf);
        Car c;
        sstr >> c;
        acc.list.push_back(c);
        getline(out, buf);
    }
    return out;
}

ostream& operator<<(ostream& out, Account& acc) {
    out << acc.name << " " << acc.surname << " " << acc.login << " " << acc.pass<<" "<<acc.money<<" "<<acc.status<<endl;
    for (auto& c : acc.list) {
        out << c<<endl;
    }
    out<<"/";
    return out;
}
