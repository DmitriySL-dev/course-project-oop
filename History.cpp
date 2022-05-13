#include "History.h"

History::History()
{
	//File f;
	//f.FromFileHistory(*this, "history.txt");
	ifstream read("history.txt");
	read >> *this;
}

History::~History()
{
	//File f;
	//f.InFileHistory(*this, "history.txt");

	ofstream read("history.txt");
	read << *this;
}

void History::WatchHistory() const
{
	int idx = 0;
	for (auto& c : user_to_action) {
		std::cout <<++idx<<". "<<"Пользователь: "<< c.first<<" Действие: "<<c.second << std::endl;
	}
}

void History::AddStrToHistory(const string& str,const string &str2)
{
	pair<string, string> pr;
	pr.first = str;
	pr.second = str2;
	user_to_action.insert(pr);
}

ostream& operator<<(ostream& out, History& hist) {
	int idx = 0;
	for (auto& c : hist.user_to_action)
	{
		out << ++idx << ". " << "Пользователь: " << c.first<< " Действие: " << c.second << std::endl;
	}
	return out;
}

istream& operator>>(istream& out, History& hist) {
	string temp,first,second;
	pair<string, string> pr;
	while (getline(out, temp)) {
		stringstream line(temp);
		line >> first; //skip 1
		line >> first; //skip 2
		line >> first;
		line >> second; //skip 3
		line >> second;
		pr.first = first;
		pr.second = second;
		hist.user_to_action.insert(pr);
	}
	return out;
}
