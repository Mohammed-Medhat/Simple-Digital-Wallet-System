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
	bool suspended;
	double balance;
	Transaction transactions;
	vector <Transaction> History;
	queue<Transaction> pendingRequests;

public:

	User();
	User(string UserName, string Password, double balance, bool sus);
	User(string UserName, string Password, double balance);
	void setUserName(string UserName);
	string getUserName();
	bool getSuspended();
	void setpassword(string pass);
	void setbalance(double bal);
	string getpassword();
	double ViewCurrentBalance();
	void userData();
	void Send();
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
	void editUsername();
	void editPassword();
	void viewPendingRequests();
	void ViewHistory();
	~User();
};