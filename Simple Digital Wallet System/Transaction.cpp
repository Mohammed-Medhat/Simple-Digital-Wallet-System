#include "Transaction.h"


Transaction::Transaction(string sender, string reciever, float amount, DATE Date)
{
	this->sender = sender;
	this->reciever = reciever;
	this->amount = amount;
	this->Date = Date;

}

void Transaction::setAmount(float amount)
{
	this->amount = amount;
}

float Transaction::getAmount()
{
	return amount;
}

void Transaction::SetSender(string sender)
{
	this->sender = sender;
}

 void Transaction::SetSender(string reciever)
{
	this->reciever = reciever;
}

 string Transaction::getSender()
{
	return sender;
}

 string Transaction::getReciever()
 {
	 return reciever;
 }

void Transaction::setAmount(float amount)
{
	this->amount = amount;
}

void Transaction::DisplayTransactionData()
{
	DATE date = getCurrentDateTime();
	cout << "sender: " << sender << endl;
	cout << "Reciever: " <<  reciever << endl;
	cout << "Paid Money : " << amount << endl;
	cout << "Time: " << date.hour << ":" << date.min << endl;
	cout << "Date: " << date.month << "/" << date.day << "/" << date.year << endl<<"------------------------------\n";
}


void Transaction::pendingRequest()
{
	DATE date = getCurrentDateTime();
	cout << "Sender :" << getSender() << endl;
	cout << "Amount: " << getAmount() << endl;
	cout << "Time: " << date.hour << ":" << date.min << endl;
	cout << "Date: " << date.month << "/" << date.day << "/" << date.year << endl;
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
	tm* ltm = localtime(&now);


	currentDateTime.hour = ltm->tm_hour;
	currentDateTime.min = ltm->tm_min;
	currentDateTime.day = ltm->tm_mday;
	currentDateTime.month = 1 + ltm->tm_mon; 
	currentDateTime.year = 1900 + ltm->tm_year; 

	return currentDateTime;
}
