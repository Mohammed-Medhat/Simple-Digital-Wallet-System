#pragma once
#include "System.h"
#include<ctime>
#include <chrono>
using namespace std;

struct DATE {
	int hour, min, day, month, year;



};

class Transaction
{
public:

	int transactionID;
	string sender, reciever;
	double amount;
	DATE Date;


public:

	Transaction();
	Transaction(string sender, string reciever, double amount, DATE Date);
	double getAmount();
	void TransactionData();
	DATE getCurrentDateTime();


	~Transaction();

};
