#pragma once
#include <iostream>
#include<ctime>
#include <chrono>
#include <stack>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct DATE {
	int hour,min, day, month, year;
};

class Transaction
{
public:

	
	string sender, reciever;
	double amount;
	DATE Date;
	

public:

	 Transaction();
	 Transaction(string sender, string reciever, double amount,DATE Date);

	 void SetSender(string sender);
	 string getSender();
	 void SetReciever(string reciever);
	 string getReciever();
	 void setAmount(double amount);
	 double getAmount();
	 void DisplayTransactionData();
	 void pendingRequest();
	 DATE getCurrentDateTime();
	 

	 ~Transaction();
	
};
