#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Transaction.h"
#include <map>
#include <queue>
#include "Admin.h"
#include "System.h"
#include <string>
#include<algorithm>
#include <sstream>


using namespace std;
class User
{
public:
	string UserName, Password;
	bool susbended;
	double balance;
	Transaction transactions;
	vector <Transaction> History;
	queue<Transaction> pendingRequests;

public:

	User();
	User(string UserName, string Password, double balance);
	void setUserName(string UserName);
	string getUserName();
	void setpassword(string pass);
	void setbalance(double bal);
	string getpassword();
	double ViewCurrentBalance();
	void userData();
	void Send(string& reciever, double& amount);
	void RequestMoney(string& sender, double amount);
	void acceptRequest(Transaction transaction);
	void addTransactionToHistory( Transaction transaction);

	void addPendingRequest( Transaction transaction);


	string serializeToString() const;
    static User deserializeFromString(const string& str); 
	bool checkSuspendedAccounts(string Reciever);
	bool CheckBalance(double amount);
	void CheckOut(string reeciever);
	void BalanceAfterTransaction(double newBalance);
	
	void viewPendingRequests();
	void ViewHistory();
	~User();
};