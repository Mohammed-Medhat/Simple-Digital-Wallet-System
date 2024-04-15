#pragma once
#include <iostream>
#include <vector>
class User
{
private:
	string UserName, Password;
	float balance;
	vector<Transaction> userTransactions;

	

protected:
	User(string UserName, string Password, float balance);
	double Send();
	double Request();
	double ViewCurrentBalance();
	Transaction ViewHistory();
	~User();
};

