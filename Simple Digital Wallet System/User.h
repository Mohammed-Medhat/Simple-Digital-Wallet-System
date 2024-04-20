#include <iostream>
#include <vector>
#include "Transaction.h"
#include <map>
#include <stack>
#include "Admin.h"
#include "System.h"

using namespace std;
class User
{
public:
	string UserName, Password;
	float balance;
	Transaction transactions;
	vector <Transaction> History;
	stack<Transaction> pendeningRequests;
	System UsersInSystem;
	Admin UsersCheckedByAdmin;
	
public:

	User();
	User(string UserName, string Password, float balance);
	void setUserName(string UserName);
	string getUserName();
	double ViewCurrentBalance();
	void userData();
	void Send(string& reciever, float& amount);
	void Request(string& reciever, float& amount);
	bool checkSuspendedAccounts(string Reciever);
	bool CheckBalance(float amount);
	void CheckOut(string reeciever);
	void BalanceAfterTransaction(float newBalance);
	void ViewHistory();
	~User();
};

