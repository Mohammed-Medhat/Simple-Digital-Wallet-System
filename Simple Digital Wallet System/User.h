#include <iostream>
#include <vector>
#include "Transaction.h"

using namespace std;
class User
{
private:
	string UserName, Password;
	float balance;

	vector <Transaction> userTransactions;

	

protected:
	User(string UserName, string Password, float balance);

	void BalanceAfterTransaction(float newBalance);
	double ViewCurrentBalance();
	
	void setUserName(string UserName);
	string getUserName();
	void userData();
	void addTransactions(Transaction T);
	vector<Transaction> getTransactions();
	void ViewHistory();
	~User();
};

