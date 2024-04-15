#pragma once
#include "Transaction.cpp"
class User
{
	string UserName, Password;
	float balance;

	double Send();
	double Request();
	double ViewCurrentBalance();
	Transaction ViewHistory();

};

