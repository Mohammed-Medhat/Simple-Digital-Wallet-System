#pragma once
#include <string>
#include <map>
#include "User.h"
#include "system.h"
#include "Transaction.h"

using namespace std;

class Admin
{
private :
	string username;
	string password;

public :
	Admin();
	Admin(string username, string password);

	static map<string, User> suspended_users;
	

	void set_username(string new_name);
	string get_username();

	void set_password(string new_pass);
	string get_password();
	
	void view_Accounts_Data();
	void edit_user(string name);
	void delete_user(string name);

	void suspend_user(string name);
	void reactivated(string name);

	void view_all_transactions();
	void edit_balance(string name,float new_balance);

	~Admin();
};

