#pragma once
#include <iostream>
#include<ctime>
#include <chrono>
#include <stack>
#include <string>
#include <stdexcept>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct DATE {
	int hour,min, day, month, year;
	string serializeToString() const {
		return std::to_string(hour) + "," + std::to_string(min) + ","
			+ std::to_string(day) + "," + std::to_string(month) + ","
			+ std::to_string(year);
	}
	static DATE deserializeFromString(const std::string& str) {
		DATE date;

		size_t pos1 = str.find(',');
		if (pos1 == std::string::npos) {
			throw std::runtime_error("Invalid serialized DATE string format");
		}
		date.hour = std::stoi(str.substr(0, pos1));

		size_t pos2 = str.find(',', pos1 + 1);
		if (pos2 == std::string::npos) {
			throw std::runtime_error("Invalid serialized DATE string format");
		}
		date.min = std::stoi(str.substr(pos1 + 1, pos2 - pos1 - 1));

		size_t pos3 = str.find(',', pos2 + 1);
		if (pos3 == std::string::npos) {
			throw std::runtime_error("Invalid serialized DATE string format");
		}
		date.day = std::stoi(str.substr(pos2 + 1, pos3 - pos2 - 1));

		size_t pos4 = str.find(',', pos3 + 1);
		if (pos4 == std::string::npos) {
			throw std::runtime_error("Invalid serialized DATE string format");
		}
		date.month = std::stoi(str.substr(pos3 + 1, pos4 - pos3 - 1));

		date.year = std::stoi(str.substr(pos4 + 1));

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
	 DATE getCurrentDateTime();
	 string serializeToString() const;
	 static Transaction deserializeFromString(string& str);

	 ~Transaction();
	
};
