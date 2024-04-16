#pragma once
#include <iostream>
#include"Transaction.cpp"
#include <vector>
class User
{

	string UserName, Password;
	float balance;
	vector <Transaction> userTransactions;

	

protected:
	
	
	double Send();
	double Request();
	double ViewCurrentBalance();
	Transaction ViewHistory();
	
public:
	User(string UserName, string Password, float balance);
	string getUserName();
	string getPassword();
	float getBalance();
	~User();
};

