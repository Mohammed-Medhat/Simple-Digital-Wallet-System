#pragma once
#include<map>
#include <fstream>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include<deque>
#include "User.h"
#include"Transaction.h"
#include"Admin.h"


using namespace std;
class User;

class System
{
public:
	static map<string, User> allUsers;
	static  User* loggedInUser;
	static vector<Transaction> allTransactions;

public:
	System();
	static void addnewUser(string&);
	static void addUser(string&, string&, double);
	static void removeUser(string&);
	static User* getUser(string username);
	bool Login(string, string);
	static void Register(string& username, string& password, double balance);
	void Logout();
	static void showAllUser();
	static bool search_user(string);
	static void readAllTransactions();
	static void writeAllTransactions();
	static void readUsersFromFile();
	static void writeUsersToFile();
	//void saveData();
	//void deleteData();
	~System();
};