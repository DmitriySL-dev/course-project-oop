#pragma once

#include "Account.h"

class Admin :public Account {
public:
	Admin();
	Admin(const string& name1, const string& surname1, const string& login1, const string& pass1);
	virtual void SetStatus() override;
};