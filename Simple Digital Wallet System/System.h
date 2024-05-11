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
#include <iostream>
#include <string>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include<assert.h>
#include <cassert>
#include <conio.h>

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
	static bool Register(string, string);
	static void Logout();
	static void showAllUser();
	static bool search_user(string);
	static void readAllTransactions();
	static void writeAllTransactions();
	static void writePendingRequests();
	static void readPendingRequests();
	static void readUsersFromFile();

	static string sha256(string& input);
	static string SecureString();

	static User* getUserForTrans(string username);
	static void writeUsersToFile();
	static void editeUser();
	//void saveData();
	//void deleteData();
	~System();
};

