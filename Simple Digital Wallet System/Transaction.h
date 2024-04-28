#pragma once
#include <iostream>
#include<ctime>
#include <chrono>
#include <queue>
#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct DATE {
	int hour, min, day, month, year;

	string serializeToString() const {
		return to_string(hour) + "," + to_string(min) + "," +
			to_string(day) + "," + to_string(month) + "," +
			to_string(year);
	}

	static DATE deserializeFromString(const string& str) {
		DATE date;

		istringstream iss(str);
		char delim;
		iss >> date.hour >> delim >> date.min >> delim >> date.day >> delim >> date.month >> delim >> date.year;

		if (iss.fail() || !iss.eof()) {
			throw invalid_argument("Invalid serialized DATE string format");
		}

		return date;
	}
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
	// bool operator==(const Transaction& other)const ;
	 bool operator==(const Transaction& other) const {
		 return sender == other.sender && reciever == other.reciever && amount == other.amount;
	 }
	 void SetSender(string sender);
	 string getSender();
	 //void SetReciever(string reciever);
	 string getReciever();
	 void setAmount(double amount);
	 double getAmount();
	 void DisplayTransactionData();
	 void pendingRequest();
	 static DATE getCurrentDateTime();
	 string serializeToString() const;
	 static Transaction deserializeFromString(string& str);

	 ~Transaction();
	
};
