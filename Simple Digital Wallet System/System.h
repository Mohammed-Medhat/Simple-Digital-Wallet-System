#pragma once
#include <vector>
#include "User.cpp"
#include"Transaction.cpp"
using namespace std;
class System
{
private:
	vector <User> allUsers;
	vector <Transaction> allTransactions;
public:
	System();
	void Login();
	void Register();
	void Edite();
	void Logout();
	void saveData();
	void deleteData();
};

