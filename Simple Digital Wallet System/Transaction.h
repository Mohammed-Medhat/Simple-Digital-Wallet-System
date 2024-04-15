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
	DATE Date;

public:
	 Transaction(string currentUser,string Reciever, float money,DATE date);

	 void fillData(string& Reciever, float& money);
	 bool CheckBalance();
	 Transaction CheckOut();
	 ~Transaction();
	
};

