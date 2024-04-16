#include <iostream>
#include"Transaction.cpp"
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


	
	
	double Send();
	double Request();
	double ViewCurrentBalance();
	Transaction ViewHistory();
	
public:
	User(string UserName, string Password, float balance);
	string getUserName();
	string getPassword();
	float getBalance();

	User(string UserName, string Password, float balance);

	double ViewCurrentBalance();
	void userData();
	void ViewHistory();

	double ViewCurrentBalance();
	void userData();
	void ViewHistory();

	~User();
};

