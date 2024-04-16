#include "User.h"

User::User(string UserName, string Password, float balance)
{
	this->UserName = UserName;
	this->Password = Password;
	this->balance = balance;
}

string User::getUserName()
{
	return UserName;
}

string User::getPassword()
{
	return Password;
}

float User::getBalance()
{
	return balance;
}
