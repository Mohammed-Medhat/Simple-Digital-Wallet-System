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
	stack<Transaction> Requests;
	System sys;
	Admin ad;
	

	
public:

	User();
	User(string UserName, string Password, float balance);

	

	void BalanceAfterTransaction(float newBalance);

	double ViewCurrentBalance();
	
	void setUserName(string UserName);
	string getUserName();
	void userData();
	


	void ViewHistory();

	void Send(string& reciever, float& amount);
	void Request(string& reciever, float& amount);
	bool checkSuspendedAccounts(string Reciever);
	bool CheckBalance(float amount);
	void CheckOut(string reeciever);


	~User();
};

