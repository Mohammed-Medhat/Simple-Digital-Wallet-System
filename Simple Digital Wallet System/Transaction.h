#include <iostream>
#include<ctime>
#include <chrono>
using namespace std;

struct DATE {
	int hour,min, day, month, year;
};

class Transaction
{
	int transactionID;
	string sender, reciever;
	float amount;
	DATE date;

public:
	 Transaction(string sender,string reciever, float amount,DATE date);

	 void fillData(string reciever, float amount);
	 bool CheckBalance();
	 Transaction CheckOut();
	 ~Transaction();
	
};

