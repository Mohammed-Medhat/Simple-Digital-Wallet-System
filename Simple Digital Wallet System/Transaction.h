#include <iostream>
#include<ctime>
#include <chrono>
#include <stack>
using namespace std;

struct DATE {
	int hour,min, day, month, year;
};

class Transaction
{

	int transactionID;
	string sender, reciever;
	float amount;
	DATE Date;

public:
	 Transaction(string currentUser,string Reciever, float money,DATE date);
 
	 void Send(string& Reciever, float& money);
	 void Request(string& Reciever, float& money);
	 void RequestMessage();

	 bool checkSuspendedAccounts(string Reciever);
	 bool CheckBalance();
	 void CheckOut();

	

	 ~Transaction();
	
};

