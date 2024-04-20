#pragma once
#include <vector>
#include "User.cpp"
#include"Transaction.cpp"
using namespace std;
class Node
{
public:
	User* value;
	Node  * left, * right;
	Node();
	Node(User* val);
};

class System
{
public:
	Node *allUsers;
	vector <Transaction> allTransactions;
	static map<string, User> AllUsers;

public:
	System();
	Node *finduser(string username,string password);
	bool isExist(string username, string password);
	void Login(string username, string password);
	void Register();
	void Edite();
	void Logout();
	void saveData();
	void deleteData();
	~System();
};

