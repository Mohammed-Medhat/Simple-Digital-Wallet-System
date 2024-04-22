#pragma once
#include "System.h"
#include"Transaction.h"
#include <stack>
#include<map>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include<deque>
using namespace std;

class User
{
public:
	string UserName, Password;
	double balance;
	bool suspended;
	Transaction transactions;
	vector <Transaction> History;
	stack<Transaction> Requests;





	User();
	User(string UserName, string Password, double balance);



	void BalanceAfterTransaction(double newBalance);

	double ViewCurrentBalance();

	void set_balance(double new_balance);
	void set_password(string new_pass);
	void setUserName(string UserName);
	string getUserName();
	void userData();



	void ViewHistory();

	void Send(string& reciever, double& amount);
	void Request(string& reciever, double& amount);
	bool checkSuspendedAccounts(string Reciever);
	bool CheckBalance(double amount);
	void CheckOut(string reeciever);


	~User();
};
