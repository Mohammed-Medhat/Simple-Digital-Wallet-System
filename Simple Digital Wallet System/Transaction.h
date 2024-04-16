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

	 Transaction();
	 Transaction(User sender,User reciever, float amount,DATE Date);

	 User getSender();
	 User getReciever();
	 float getAmount();
 
	 void Send(User& reciever, float& amount);
	 void Request(User& reciever, float& amount);
	 void RequestMessage();

	 bool checkSuspendedAccounts(User Reciever);
	 bool CheckBalance(User sender, float amount);
	 void CheckOut();

	 void sendingTransaction();
	 void recievingTransaction();

	 

	 ~Transaction();
	
};

