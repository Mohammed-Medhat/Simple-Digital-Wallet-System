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
	User sender, reciever;
	float amount;
	DATE Date;
	

public:
	 Transaction(User currentUser,User Reciever, float money,DATE date);
 
	 void Send(User& Reciever, float& money);
	 void Request(User& Reciever, float& money);
	 void RequestMessage();

	 bool checkSuspendedAccounts(User Reciever);
	 bool CheckBalance();
	 void CheckOut();

	 void displayTransactionData();

	 ~Transaction();
	
};

