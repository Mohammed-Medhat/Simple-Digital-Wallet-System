#include "Transaction.h"
#include "User.h"

Transaction::Transaction(User sender, User reciever, float amount, DATE Date)
{
	this->sender = sender;
	this->reciever = reciever;
	this->amount = amount;
	this->Date = Date;

}


User Transaction::getReciever()
{
	return reciever;
}

User Transaction::getSender()
{
	return sender;
}

float Transaction::getAmount()
{
	return amount;
}


void Transaction::Send(User& reciever, float& amount)
{
	string recieverName;
	bool T;

	cout << "Enter the reciever name: "<<endl;
	cin >> recieverName;
	reciever.setUserName(recieverName);
	cout << "Enter the amount: " << endl;


	if (checkSuspendedAccounts(reciever))
	{ 
		cout << "This account was inactive" << endl << "Do you want to continue? press 1 / 0 to exit";
		cin >> T;
		if (T == 1) {
			Send(reciever, amount);
		}
		else
		{
			exit; //redirect to home page
		}
	}
	else if (!CheckBalance(sender, amount))
	{
		cout << "Your balance is not enough" << endl << "Do you want to continue? press 1 / 0 to exit";
		cin >> T;
		if (T == 1) {
			Send(reciever, amount);
		}
		else
		{
			exit; //redirect to home page
		}
	}

	else
	{
		CheckOut();
	}


}

bool Transaction::CheckBalance(User sender, float amount)
{
	return(sender.ViewCurrentBalance() >= amount);
}

void Transaction::sendingTransaction()
{
	DATE date = getCurrentDateTime();
	cout << "Reciever: " << getReciever().getUserName() << endl;
	cout << "Paid Money : " << getAmount() << endl;
	cout << "Time: " << date.hour << ":" << date.min << endl;
	cout << "Date: " << date.month << "/" << date.day << "/" << date.year << endl;
}

void Transaction::recievingTransaction()
{
	DATE date = getCurrentDateTime();
	cout << "Sender: " << getSender().getUserName() << endl;
	cout << "Recieved Money : " << getAmount() << endl;
	cout << "Time: " << date.hour << ":" << date.min << endl;
	cout << "Date: " << date.month << "/" << date.day << "/" << date.year << endl << endl;
}



void Transaction::CheckOut()
{

	sendingTransaction();
	
	bool T;



	cout << "confirm transaction" << endl << "press 1 to confirm / 0 to delete transaction";

	cin >> T;
	if (T == 1)
	{
		transactionID++;

		float SenderNewBalance = getSender().ViewCurrentBalance() - getAmount();
		float RecieverNewBalance = getReciever().ViewCurrentBalance() + getAmount();

		getSender().BalanceAfterTransaction(SenderNewBalance);
		getReciever().BalanceAfterTransaction(RecieverNewBalance);

		getSender().addTransactions(*this);
		getReciever().addTransactions(*this);

	}

	else
	{
		exit; //redirect to home page
	}
	

}




//
//void Transaction::Send(User& Reciever, float& money)
//{
//	string T;
//
//	cout << "Enter the reciever Name:"<<endl;
//	cin >> Reciever;
//
//	cout << "Enter the amount:" << endl;
//	cin >> money;
//
//	if (!CheckBalance())
//	{
//		cout << "There is not enough balance."<<endl<<"Do you want to contine? yes/no";
//		cin >> T;
//
//		while (T != "yes" || T != "no")
//		{
//			cout << "invalid";
//			cin >> T;
//		}
//
//		if (T == "yes")
//		{
//			Send(Reciever, money);
//		}
//
//		else if (T == "no")
//		{
//			exit; //redirect url to home page
//		}
//		
//	}
//
//
//	else
//	{
//		CheckOut();
//	}
//}
//
//
//bool Transaction::CheckBalance()
//{
//	return(amount <= );
//}
//
//void Transaction::CheckOut()
//{
//	DATE date = getCurrentDateTime();
//	bool T;
//
//	cout << "Receiver: " << reciever<<endl;
//	cout << "paid money: " << amount<<endl;
//	cout << "Time: " << date.hour << ":" << date.min<<endl;
//	cout << "Date: " << date.month << "/" << date.day << "/" << date.year << endl;
//
//	cout << "confirm transaction" << endl << "press 1 to confirm / 0 to delete transaction";
//	if (T == 1)
//	{
//		transactionID++;
//		//currentUser.balance -= amount
//		//recieverUser.balance += amount
//
//		
//	}
//	else
//	{
//		exit; // redirect to transaction page 
//	}
//
//}
//
//
//
//void Transaction::Request(string& Reciever, float& money)
//{
//	bool T;
//	cout << "Request will be sent to: "<<endl;
//	cin >> Reciever;
//
//	if (checkSuspendedAccounts(Reciever))
//	{
//		cout << "This account is suspended" << endl << "Do you want to continue? press 1 to continue / 0 to exit"<<endl;
//		cin >> T;
//		if (T == 1)
//			Request(Reciever, money);
//		else
//			exit; //redirect to home page
//	}
//	cout << "Enter the requested amount: "<<endl;
//	cin >> money;
//
//	cout << "Request was sent successfully";
//
//}
//
//bool Transaction::checkSuspendedAccounts(string Reciever)
//{
//
//}





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
