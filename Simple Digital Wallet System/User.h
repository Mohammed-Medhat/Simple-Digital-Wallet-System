#include <iostream>
#include <vector>
#include "Transaction.h"
#include <map>
#include <list>
#include "Admin.h"


using namespace std;
class User
{
public:
	string UserName, Password;
	float balance;
	Transaction transactions;
	vector <Transaction> History;
	list<Transaction> pendingRequests;
	System UsersInSystem;
	Admin UsersCheckedByAdmin;
	
public:

	User();
	User(string UserName, string Password, float balance);
	void setUserName(string UserName);
	string getUserName();
	double ViewCurrentBalance();
	void userData();
	void Send(string& reciever, float& amount);
	void RequestMoney(string& sender, float amount);

	void acceptRequest(Transaction transaction);
	

	bool checkSuspendedAccounts(string Reciever);
	bool CheckBalance(float amount);
	void CheckOut(string reeciever);
	void BalanceAfterTransaction(float newBalance);
	void declineRequest(Transaction transaction);
	void viewPendingRequests();
	void ViewHistory();
	~User();
};
