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
public:

	
	string sender, reciever;
	float amount;
	DATE Date;
	

public:

	 Transaction();
	 Transaction(string sender, string reciever, float amount,DATE Date);

	 void SetSender(string sender);
	 string getSender();
	 void SetReciever(string reciever);
	 string getReciever();
	 void setAmount(float amount);
	 float getAmount();
	 void DisplayTransactionData();
	 void pendingRequest();
	 DATE getCurrentDateTime();
	 

	 ~Transaction();
	
};
