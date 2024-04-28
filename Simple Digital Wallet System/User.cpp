#pragma once
#include "User.h"

User::User()
{
}

User::User(string UserName, string Password, double balance)
{
	this->UserName = UserName;
	this->Password = Password;
	this->balance = balance;
}

void User::BalanceAfterTransaction(double newBalance)
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

void User::setpassword(string pass)
{
	Password = pass;
}

void User::setbalance(double bal)
{
	balance = bal;
}

string User::getpassword()
{
	return Password;
}

void User::userData()
{
	cout << "User Name: " << getUserName()<<"\t";
	cout << "Balance: " << ViewCurrentBalance()<<endl;
	ViewHistory();
}
void User::Send(string& reciever, double& amount)
{

	bool T;
	
	map<string, User>::iterator FindingUser;
	FindingUser = System::allUsers.find(reciever);

	if (FindingUser == System::allUsers.end()) {
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
		transactions.amount = amount;
		transactions.sender = System::loggedInUser->getUserName();
		transactions.reciever = reciever;
		transactions.Date= Transaction::getCurrentDateTime();
		CheckOut(reciever);
	}


}


bool User::checkSuspendedAccounts(string Reciever)
{
	map<string, User>::iterator R;
	R = Admin::suspended_users.find(Reciever);
	if (R == Admin::suspended_users.end())
		return false;
	else
		return true;

}


void User::ViewHistory()
{
	if (History.empty()) {
		cout << "There is no transaction made/n";
		return;
	}
	else {
		cout << "Your Transaction History: " << endl << "**************\n";

		for  (Transaction t : History) {
			t.DisplayTransactionData();
		}
	}
}




// display out the message to enter username and amount - Entering username and amount in system



bool User::CheckBalance(double amount)
{
	return(ViewCurrentBalance() >= amount || (amount > 0));
}


void User::CheckOut(string reciever)
{
	DATE TransactionDate = transactions.getCurrentDateTime();
	bool T;
	



	cout << "Receiver: " << reciever<<endl;
	cout << "Paid Amount: " << transactions.getAmount()<<endl;
	cout << "Time: " << TransactionDate.hour << ":" << TransactionDate.min << endl;
	cout << "Date: " << TransactionDate.month << "/" << TransactionDate.day << "/" << TransactionDate.year << endl;
	cout << "confirm transaction" << endl << "press 1 to confirm / 0 to delete transaction";

	cin >> T;
	
	if (T == 1)
	{
		
		
		User *Reciever = System::getUser(reciever);
		

		double SenderNewBalance = ViewCurrentBalance() - transactions.getAmount();
		
		double RecieverNewBalance = Reciever->ViewCurrentBalance() + transactions.getAmount();
		
		BalanceAfterTransaction(SenderNewBalance);
		
		
		Reciever->BalanceAfterTransaction(RecieverNewBalance);
		
		History.push_back(transactions);
		
		Reciever->History.push_back(transactions);
		System::allTransactions.push_back(transactions);
		

	}

	else
	{
		exit; //redirect to home page
	}


}







void User::RequestMoney(string& sender, double amount) {

	bool T;

	map<string, User>::iterator R;
	 R = System::allUsers.find(sender);
	User *FindingUser = &R->second;

	if (R == System::allUsers.end()) {
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

		FindingUser->pendingRequests.push(transactions);
		// display out pending request in system
	}

	
	
}




void User::acceptRequest(Transaction transactions) {

	double newBalanceOfReciever = ViewCurrentBalance() - transactions.getAmount();
	BalanceAfterTransaction(newBalanceOfReciever);
	


	User *FindingUser = System::getUser(transactions.getSender());

	double newBalanceOfSender = ViewCurrentBalance() + transactions.getAmount();
	FindingUser->BalanceAfterTransaction(newBalanceOfSender);

	cout << "transaction completed successfully";

	History.push_back(transactions);
	FindingUser->History.push_back(transactions);
	pendingRequests.pop();

}

void User::addTransactionToHistory( Transaction transaction)
{
	
		History.push_back(transaction);

}

void User::addPendingRequest( Transaction transaction)
{
		pendingRequests.push(transaction);

}

string User::serializeToString() const
{
	ostringstream oss;
	oss << UserName << "|" << Password << "|" << balance << "\n";

	for (const auto& transaction : History) {
		oss << "History:" << transaction.serializeToString() << "\n";
	}
	queue<Transaction> tempQueue = pendingRequests;
	while (!tempQueue.empty()) {
		const auto& request = tempQueue.front();
		oss << "PendingRequest:" << request.serializeToString() << "\n";
		tempQueue.pop();
	}

	return oss.str();
}

User User::deserializeFromString(const string& str)
{
	istringstream iss(str);
	string token;

	// Read UserName
	getline(iss, token, '|');
	string userName = token;

	// Read Password
	getline(iss, token, '|');
	string password = token;

	// Read balance
	getline(iss, token, '|');
	double balance = stod(token);

	User user(userName, password, balance);

	// Read remaining lines for History and PendingRequest
	while (getline(iss, token)) {
		if (!token.empty()) {
			if (token.find("History:") == 0) {
				string historyData = token.substr(8); // Extract the transaction part
				Transaction historyTransaction = Transaction::deserializeFromString(historyData);
				user.addTransactionToHistory(historyTransaction);
			}
			else if (token.find("PendingRequest:") == 0) {
				string requestData = token.substr(15); // Extract the transaction part
				Transaction requestTransaction = Transaction::deserializeFromString(requestData);
				user.addPendingRequest(requestTransaction);
			}
		}
	}

	return user;
}




//

void User::viewPendingRequests() {
	cout << "Pending requests for User: " << UserName << endl;
	if (pendingRequests.empty()) {
		cout << "No pending requests." << endl;
	}
	else 
	{
		while (!pendingRequests.empty()) {
			int i = 1;
			Transaction request = pendingRequests.front(); // Get the front element of the queue
			
			cout << "Request " << (i + 1) << ": Sender: " << request.getSender() << ", Amount: " << request.getAmount() << endl;
			cout << "Do you want to Accept(A) or Decline(D) this request? (A/D): ";
			char choice;
			cin >> choice;
			if (choice == 'A' || choice == 'a') {
				pendingRequests.pop();
				cout << "Request accepted." << endl;
			}

			else if (choice == 'D' || choice == 'd') {
				pendingRequests.pop();
				cout << "Request declined." << endl;
			}
			
			i++;
		
		}
		if (pendingRequests.empty()) {
			cout << "No more pending requests." << endl;
		}

	}
}


User::~User(void) {
	
}
