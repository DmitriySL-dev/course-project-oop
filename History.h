#pragma once

#include <iostream>
#include <map>
#include <sstream>

#include "File.h"

using std::multimap;
using std::string;
using std::pair;

class History { //Класс полной отчетности действий
public:
	History();
	~History();

	void WatchHistory() const;

	void AddStrToHistory(const string& str,const string &str2);

private:
	multimap<string,string> user_to_action;

	friend ostream& operator<<(ostream& out, History& hist);
	friend istream& operator>>(istream& out, History& hist);
};
