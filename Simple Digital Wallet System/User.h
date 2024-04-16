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

	double ViewCurrentBalance();
	void userData();
	void ViewHistory();
	~User();
};

