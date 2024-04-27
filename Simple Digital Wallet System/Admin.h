#pragma once
#include <iostream>
#include "System.h"
#include "Transaction.h"


using namespace std;
class User;
class Admin
{
private:
	string username;
	string password;
public:
	
	static map<string,User> suspended_users;

	Admin();
	Admin(string, string);
	

	void set_username(string new_name);
	string get_username();

	void set_password(string new_pass);
	string get_password();

	void view_Accounts_Data();

	static  void edit_username(string name);
	static void edit_password(string name);
	void add_user();
	void delete_user();

	void suspend_user();
	void reactivated();

	void view_all_transactions();
	
	void edit_balance(string name);
	~Admin();
};

