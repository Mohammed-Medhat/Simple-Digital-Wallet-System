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


	
	
	double Send();
	double Request();
	
	Transaction ViewHistory();
	
public:
	User(string UserName, string Password, float balance);
	string getUserName();
	string getPassword();
	float getBalance();



	double ViewCurrentBalance();
	void userData();
	//void ViewHistory();


	~User();
};

