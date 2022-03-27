#pragma once

#include "Account.h"

class User :public Account {
public:
	User();
	User(const string& name1, const string& surname1, const string& login1, const string& pass1);
	virtual void SetStatus() override;
};