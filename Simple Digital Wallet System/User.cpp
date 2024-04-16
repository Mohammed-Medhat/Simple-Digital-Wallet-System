#include "User.h"
User::User(string UserName, string Password, float balance)
{
	this->UserName = UserName;
	this->Password = Password;
	this->balance = balance;
}

void User::BalanceAfterTransaction(float newBalance)
{
	this->balance = newBalance;
}

double User::ViewCurrentBalance()
{
	return balance;
}

void User::setUserName(string UserName)
{
	this->UserName = UserName;
}

string User::getUserName()
{
	return UserName;
}

void User::userData()
{
	cout << "User Name: " << getUserName();
	cout << "Balance: " << ViewCurrentBalance();

}

void User::addTransactions(Transaction T)
{
	userTransactions.push_back(T);
}

vector<Transaction> User:: getTransactions()
{
	return userTransactions;
}



void User::ViewHistory()
{
	if (!userTransactions.empty())
	{
		for (auto& trans : userTransactions)
		{
			trans.displayTransactionData();
		}
	}
}

