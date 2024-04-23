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

		for (int i = 0; i < History.size(); i++) {
			transactions.DisplayTransactionData();
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
	



	cout << "Reciever: " << reciever<<endl;
	cout << "Paid Amount: " << transactions.getAmount()<<endl;
	cout << "Time: " << TransactionDate.hour << ":" << TransactionDate.min << endl;
	cout << "Date: " << TransactionDate.month << "/" << TransactionDate.day << "/" << TransactionDate.year << endl;
	cout << "confirm transaction" << endl << "press 1 to confirm / 0 to delete transaction";

	cin >> T;
	
	if (T == 1)
	{
		map<string, User>::iterator R;
		 R = System::allUsers.find(reciever);
		User Reciever = R->second;
		

		double SenderNewBalance = ViewCurrentBalance() - transactions.getAmount();
		double RecieverNewBalance = Reciever.ViewCurrentBalance() + transactions.getAmount();

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







void User::RequestMoney(string& sender, double amount) {

	bool T;

	map<string, User>::iterator R;
	 R = System::allUsers.find(sender);
	User FindingUser = R->second;

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

		FindingUser.pendingRequests.push_back(transactions);
		// display out pending request in system
	}

	
	
}




void User::acceptRequest(Transaction transactions) {

	double newBalanceOfReciever = ViewCurrentBalance() - transactions.getAmount();
	BalanceAfterTransaction(newBalanceOfReciever);
	map<string, User>::iterator R;
	 R = System::allUsers.find(transactions.getSender());


	User FindingUser = R->second;

	double newBalanceOfSender = ViewCurrentBalance() + transactions.getAmount();
	FindingUser.BalanceAfterTransaction(newBalanceOfSender);

	cout << "transaction completed successfully";

	History.push_back(transactions);
	FindingUser.History.push_back(transactions);
	declineRequest(transactions);

}

string User::serializeToString() const
{
	std::string serializedData;

	serializedData += UserName + "|" + Password + "|" + std::to_string(balance) + "\n";

	for (const auto& transaction : History) {
		serializedData += "History:" + transaction.serializeToString() + "\n";
	}

	for (const auto& request : pendingRequests) {
		serializedData += "PendingRequest:" + request.serializeToString() + "\n";
	}

	return serializedData;
}

User User::deserializeFromString(const std::string& str)
{
	std::istringstream iss(str);
	std::string line;
	getline(iss, line); // Read first line (User data)
	size_t pos = line.find('|');
	if (pos == std::string::npos) {
		throw std::runtime_error("Invalid serialized User string format: Missing '|' separator");
	}
	std::string name = line.substr(0, pos);
	line.erase(0, pos + 1);

	pos = line.find('|');
	if (pos == std::string::npos) {
		throw std::runtime_error("Invalid serialized User string format: Missing '|' separator");
	}
	std::string password = line.substr(0, pos);
	line.erase(0, pos + 1);

	// Check if there is anything left in the line for balance
	if (line.empty()) {
		throw std::runtime_error("Invalid serialized User string format: Missing balance");
	}
	double balance = std::stod(line);

	User user(name, password, balance);

	// Read remaining lines (History and PendingRequest)
	while (getline(iss, line)) {
		pos = line.find(':');
		if (pos == std::string::npos) {
			throw std::runtime_error("Invalid serialized User string format: Missing ':' separator");
		}
		std::string section = line.substr(0, pos);
		line.erase(0, pos + 1);

		if (section == "History") {
			user.History.push_back(Transaction::deserializeFromString(line));
		}
		else if (section == "PendingRequest") {
			user.pendingRequests.push_back(Transaction::deserializeFromString(line));
		}
		else {
			throw std::runtime_error("Invalid section in serialized User string: " + section);
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
User::~User(void) {
	cout << "end";
}
