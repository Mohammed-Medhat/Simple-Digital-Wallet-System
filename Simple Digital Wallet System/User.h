#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Transaction.h"
#include <map>
#include <list>
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
	double balance;
	Transaction transactions;
	vector <Transaction> History;
	list<Transaction> pendingRequests;

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
    static User deserializeFromString(const std::string& str); 
	bool checkSuspendedAccounts(string Reciever);
	bool CheckBalance(double amount);
	void CheckOut(string reeciever);
	void BalanceAfterTransaction(double newBalance);
	void declineRequest(Transaction transaction);
	void viewPendingRequests();
	void ViewHistory();
	~User();
};