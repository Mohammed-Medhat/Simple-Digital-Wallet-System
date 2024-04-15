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
	double Send();
	double Request();
	double ViewCurrentBalance();
	Transaction ViewHistory();

};

