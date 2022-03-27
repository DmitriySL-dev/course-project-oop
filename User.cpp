#include "User.h"

User::User()
{
}

User::User(const string& name1, const string& surname1, const string& login1, const string& pass1)
{
	name = name1;
	surname = surname1;
	login = login1;
	pass = pass1;
}

void User::SetStatus()
{
	status = "Польз.";
}
