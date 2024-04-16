#include <iostream>
#include"Transaction.cpp"
#include <vector>
#include "Transaction.h"

using namespace std;
class User
{

	string UserName, Password;
	float balance;
	vector <Transaction> userTransactions;

	

protected:
<<<<<<< HEAD

	
	
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

=======
	User(string UserName, string Password, float balance);

	double ViewCurrentBalance();
	void userData();
	void ViewHistory();
>>>>>>> 0e2c95e9ff25db2aea9316f8a23439dfbfde4dcb
	~User();
};

