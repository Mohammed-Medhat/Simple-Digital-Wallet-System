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
	cout << "User Name: " << getUserName() << "\t";
	cout << "Balance: " << ViewCurrentBalance() << endl;
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


	auto FindingUser = UsersInSystem.allUsers.find(reciever);

	if (FindingUser == UsersInSystem.allUsers.end()) {
		cout << "The User is not found" << endl << "Do you want to continue? press 1 / 0 to exit";
		cin >> T;
		if (T == 1)
		{
			cin >> reciever;
			cin >> amount;
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
			cin >> reciever;
			cin >> amount;
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
			cin >> reciever;
			cin >> amount;
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
	return(ViewCurrentBalance() >= amount || (amount > 0));
}


void User::CheckOut(string reciever)
{
	DATE TransactionDate = transactions.getCurrentDateTime();
	bool T;




	cout << "Reciever: " << reciever << endl;
	cout << "Paid Amount: " << transactions.getAmount() << endl;
	cout << "Time: " << TransactionDate.hour << ":" << TransactionDate.min << endl;
	cout << "Date: " << TransactionDate.month << "/" << TransactionDate.day << "/" << TransactionDate.year << endl;
	cout << "confirm transaction" << endl << "press 1 to confirm / 0 to delete transaction";

	cin >> T;

	if (T == 1)
	{
		auto R = System::allUsers.find(reciever);
		User Reciever = R->second;


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



bool User::checkSuspendedAccounts(string Reciever)
{

	/*suspended_users.find(Reciever);*/
	auto R = Admin::suspended_users.find(Reciever);
	if (R == Admin::suspended_users.end())
		return false;
	else
		return true;

}



void User::RequestMoney(string& sender, float amount) {

	bool T;


	auto R = System::allUsers.find(sender);
	User FindingUser = R->second;

	if (R == UsersInSystem.allUsers.end()) {
		cout << "The User is not found" << endl << "Do you want to continue? press 1 / 0 to exit";
		cin >> T;
		if (T == 1)
		{
			cin >> sender;
			cin >> amount;
			RequestMoney(sender, amount);
		}
		else
		{
			exit; //redirect to home page 
		}
	}


	else if (checkSuspendedAccounts(sender))
	{
		cout << "This account was inactive" << endl << "Do you want to continue? press 1 / 0 to exit";
		cin >> T;
		if (T == 1) {
			cin >> sender;
			cin >> amount;
			RequestMoney(sender, amount);
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
			cin >> sender;
			cin >> amount;
			RequestMoney(sender, amount);
		}
		else
		{
			exit; //redirect to home page
		}
	}



	else
	{

		cout << "Request is sent successfully";
		transactions.setAmount(amount);
		transactions.SetSender(getUserName());

		FindingUser.pendingRequests.push_back(transactions);
		// display out pending request in system
	}



}






void User::acceptRequest(Transaction transactions) {

	float newBalanceOfReciever = ViewCurrentBalance() - transactions.getAmount();
	BalanceAfterTransaction(newBalanceOfReciever);

	auto R = System::allUsers.find(transactions.getSender());


	User FindingUser = R->second;

	float newBalanceOfSender = ViewCurrentBalance() + transactions.getAmount();
	FindingUser.BalanceAfterTransaction(newBalanceOfSender);

	cout << "transaction completed successfully";

	History.push_back(transactions);
	FindingUser.History.push_back(transactions);
	declineRequest(transactions);

}
//

void User::viewPendingRequests() {
	cout << "Pending requests for User: " << UserName << endl;
	if (pendingRequests.empty()) {
		cout << "No pending requests." << endl;
	}
	else
	{
		for (auto it = pendingRequests.begin(); it != pendingRequests.end(); it++) {
			int i = 1;
			cout << "Request " << (i + 1) << ": Sender: " << (*it).getSender() << ", Amount: " << (*it).getAmount() << endl;
			cout << "Do you want to Accept(A) or Decline(D) this request? (A/D): ";
			char choice;
			cin >> choice;
			if (choice == 'A' || choice == 'a') {
				acceptRequest((*it));
				cout << "Request accepted." << endl;
			}
			else if (choice == 'D' || choice == 'd') {
				declineRequest((*it));
				cout << "Request declined." << endl;
			}
			else {
				cout << "Skipping Request" << endl;
			}
			i++;

		}

	}
}

void User::declineRequest(Transaction transactions) {
	auto it = find(pendingRequests.begin(), pendingRequests.end(), transactions);
	if (it != pendingRequests.end()) {
		pendingRequests.erase(it);
	}
}