#include "Transaction.h"
#include "User.h"

Transaction::Transaction(string currentUser, string Reciever, float money, DATE date)
{

	transactionID = 0;
	sender = currentUser;
	reciever = Reciever;
	amount = money;
	Date = date;

}

void Transaction::fillData(string& Reciever, float& money)
{
	string T;

	cout << "Enter the reciever Name:"<<endl;
	cin >> Reciever;

	cout << "Enter the amount:" << endl;
	cin >> money;

	if (!CheckBalance())
	{
		cout << "There is not enough balance."<<endl<<"Do you want to contine? yes/no";
		cin >> T;

		while (T != "yes" || T != "no")
		{
			cout << "invalid";
			cin >> T;
		}

		if (T == "yes")
		{
			fillData(Reciever, money);
		}

		else if (T == "no")
		{
			exit; //redirect url to home page
		}
		
	}


	else
	{
		CheckOut();
	}
}

bool Transaction::CheckBalance()
{
	return(amount <= balance);
}

Transaction Transaction::CheckOut()
{
	DATE date = getCurrentDateTime();
	bool T;

	cout << "Receiver: " << reciever<<endl;
	cout << "paid money: " << amount<<endl;
	cout << "Time: " << date.hour << ":" << date.min<<endl;
	cout << "Date: " << date.month << "/" << date.day << "/" << date.year << endl;

	cout << "confirm transaction" << endl << "press 1 to confirm / 0 to delete transaction";
	if (T == 1)
	{
		transactionID++;
		userTransactions.Push_back(Transaction);
	}
	else
	{
		exit; // redirect to transaction page 
	}

}


DATE getCurrentDateTime() {
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
