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
private:

	int transactionID;
	string sender, reciever;
	float amount;
	DATE Date;
	

public:

	 Transaction();
	 Transaction(string sender, string reciever, float amount,DATE Date);


	 float getAmount();
 





	 void TransactionData();
	 DATE getCurrentDateTime();
	 

	 ~Transaction();
	
};

