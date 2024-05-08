#pragma once
#include<map>
#include <fstream>
#include <iomanip>
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
	static vector<Transaction> allPendingRequests;

public:
	System();
	static void addnewUser(string&);
	static void removeUser(string&);
	static User* getUser(string username);
	static bool Login();
	static bool Register();
	static void Logout();
	static void showAllUser();
	static bool search_user(string);
	static void readAllTransactions();
	static void writeAllTransactions();
	static void writePendingRequests();
	static void readPendingRequests();
	static void readUsersFromFile();

	string md5(const string& input);
	string SecureString();

	static User* getUserForTrans(string username);
	static void writeUsersToFile();
	static void editeUser();
	//void saveData();
	//void deleteData();
	~System();
};

