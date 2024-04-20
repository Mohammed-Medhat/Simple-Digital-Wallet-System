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
	cout << "User Name: " << getUserName()<<"\t";
	cout << "Balance: " << ViewCurrentBalance()<<endl;
	ViewHistory();
}





void User::ViewHistory()
{
	if (History.empty()) {
		cout << "There is no transaction made/n";
		return;
	}
	else {
		cout << "Your Transaction History: " << endl << "**************\n";

		for (int i = 0; i < History.size(); i++) {
			transactions.DisplayTransactionData();
		}
	}
}




// display out the message to enter username and amount - Entering username and amount in system

void User::Send(string& reciever, float& amount)
{
	bool T;
	

	auto FindingUser = UsersInSystem.AllUsers.find(reciever);

	if (FindingUser == UsersInSystem.AllUsers.end()) {
		cout << "The User is not found" << endl << "Do you want to continue? press 1 / 0 to exit";
		cin >> T;
		if (T == 1)
		{
			Send(reciever, amount);
		}
		else
		{
			exit; //redirect to home page 
		}
	}


	else if (checkSuspendedAccounts(reciever))
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
	else if (!CheckBalance(amount))
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
		CheckOut(reciever);
	}


}

bool User::CheckBalance(float amount)
{
	return(ViewCurrentBalance() >= amount && (amount > 0));
}


void User::CheckOut(string reciever)
{
	DATE TransactionDate = transactions.getCurrentDateTime();
	bool T;
	



	cout << "Reciever: " << reciever<<endl;
	cout << "Paid Amount: " << transactions.getAmount()<<endl;
	cout << "Time: " << TransactionDate.hour << ":" << TransactionDate.min << endl;
	cout << "Date: " << TransactionDate.month << "/" << TransactionDate.day << "/" << TransactionDate.year << endl;
	cout << "confirm transaction" << endl << "press 1 to confirm / 0 to delete transaction";

	cin >> T;
	
	if (T == 1)
	{
		User Reciever = UsersInSystem.AllUsers.find(reciever);
		

		float SenderNewBalance = ViewCurrentBalance() - transactions.getAmount();
		float RecieverNewBalance = Reciever.ViewCurrentBalance() + transactions.getAmount();

		BalanceAfterTransaction(SenderNewBalance);
		
		Reciever.BalanceAfterTransaction(RecieverNewBalance);
		
		History.push_back(transactions);
		Reciever.History.push_back(transactions);


	}

	else
	{
		exit; //redirect to home page
	}


}



void User::Request(string& reciever, float& amount)
{

}

bool User::checkSuspendedAccounts(string Reciever)
{
		
	auto SuspendedUser = UsersCheckedByAdmin.suspended_users.find(Reciever);
}