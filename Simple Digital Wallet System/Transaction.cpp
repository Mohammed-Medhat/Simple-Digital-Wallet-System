#pragma once
#include "Transaction.h"

Transaction::Transaction()
{

	this->sender = "invalid";
	this->reciever = "invalid";
	this->amount = 0;



}

Transaction::Transaction(string sender, string reciever, double amount)
{
	this->sender = sender;
	this->reciever = reciever;
	this->amount = amount;
	this->Date = getCurrentDateTime();

}

//bool Transaction::operator==(const Transaction& other) const
//{
//	return sender == other.sender && reciever == other.reciever && amount == other.amount;
//
//}


void Transaction::setAmount(double amount)
{
	this->amount = amount;
}

double Transaction::getAmount()
{
	return amount;
}

void Transaction::SetSender(string sender)
{
	this->sender = sender;
}



string Transaction::getSender()
{
	return sender;
}

string Transaction::getReciever()
{
	return reciever;
}



void Transaction::DisplayTransactionData()
{

	cout << "sender: " << sender << endl;
	cout << "Receiver: " << reciever << endl;
	cout << "Paid Money : " << amount << endl;
	cout << "Time: " << Date.hour << ":" << Date.min << endl;
	cout << "Date: " << Date.month << "/" << Date.day << "/" << Date.year << endl << "------------------------------\n";
}


void Transaction::pendingRequest()
{
	DATE date = getCurrentDateTime();
	cout << "Sender :" << getSender() << endl;
	cout << "Amount: " << getAmount() << endl;
	cout << "Time: " << date.hour << ":" << date.min << endl;
	cout << "Date: " << date.month << "/" << date.day << "/" << date.year << endl;
}


DATE Transaction::getCurrentDateTime() {
	DATE currentDateTime;
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now); // Correct usage of localtime_s

	currentDateTime.hour = ltm.tm_hour;
	currentDateTime.min = ltm.tm_min;
	currentDateTime.day = ltm.tm_mday;
	currentDateTime.month = 1 + ltm.tm_mon;
	currentDateTime.year = 1900 + ltm.tm_year;

	return currentDateTime;
}

string Transaction::serializeToString() const
{
	if (sender.empty() && reciever.empty() && amount == 0.0 && Date.hour == 0 && Date.min == 0 && Date.day == 0 && Date.month == 0 && Date.year == 0) {
		return ""; // Return empty string for empty transaction
	}
	ostringstream oss;
	oss << sender << "|" << reciever << "|";

	// Set formatting options to prevent scientific notation for amount
	oss << std::fixed << std::setprecision(3) << amount << "|";

	oss << Date.serializeToString();
	return oss.str();
}

Transaction Transaction::deserializeFromString(string& str)
{
	try {
		size_t pos1 = str.find('|');
		if (pos1 == string::npos)
			throw invalid_argument("Invalid serialized Transaction string format: Missing sender");

		size_t pos2 = str.find('|', pos1 + 1);
		if (pos2 == string::npos)
			throw invalid_argument("Invalid serialized Transaction string format: Missing receiver");

		size_t pos3 = str.find('|', pos2 + 1);
		if (pos3 == string::npos)
			throw invalid_argument("Invalid serialized Transaction string format: Missing amount");

		string sndr = str.substr(0, pos1);
		string rcvr = str.substr(pos1 + 1, pos2 - pos1 - 1);
		string amtStr = str.substr(pos2 + 1, pos3 - pos2 - 1);
		double amt = stod(amtStr);

		string dateStr = str.substr(pos3 + 1);
		DATE dt = DATE::deserializeFromString(dateStr);

		return Transaction(sndr, rcvr, amt);
	}
	catch (const exception& e) {
		throw runtime_error("Error deserializing Transaction: " + string(e.what()));
	}
}




Transaction::~Transaction()
{
}

