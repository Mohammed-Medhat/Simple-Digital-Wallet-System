#pragma once
class User
{
	string UserName, Password;
	float balance;

	double Send();
	double Request();
	double ViewCurrentBalance();
	Transactions ViewHistory();

};

