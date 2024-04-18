#include "Transaction.h"
#include "User.h"
#include "Admin.h"

Transaction::Transaction(string sender, string reciever, float amount, DATE Date)
{
	this->sender = sender;
	this->reciever = reciever;
	this->amount = amount;
	this->Date = Date;

}


void Transaction::TransactionData()
{
	DATE date = getCurrentDateTime();
	cout << "sender: " << sender << endl;
	cout << "Reciever: " <<  reciever << endl;
	cout << "Paid Money : " << amount << endl;
	cout << "Time: " << date.hour << ":" << date.min << endl;
	cout << "Date: " << date.month << "/" << date.day << "/" << date.year << endl<<"------------------------------\n";
}



// system Transactions  send + recievce


DATE Transaction::getCurrentDateTime() {
	DATE currentDateTime;
	time_t now = time(0);
	tm* ltm = localtime(&now);

	// Set the current date and time components
	currentDateTime.hour = ltm->tm_hour;
	currentDateTime.min = ltm->tm_min;
	currentDateTime.day = ltm->tm_mday;
	currentDateTime.month = 1 + ltm->tm_mon; // Month is 0-based, so add 1
	currentDateTime.year = 1900 + ltm->tm_year; // Years since 1900

	return currentDateTime;
}
