#pragma once
#include <string>

using namespace std;

class Admin
{
private :
	string username;
	string password;

protected :
	
	void set_username(string new_name);
	string get_username();

	void set_password(string new_pass);
	string get_password();
	
	void view_Accounts_Data();
	void edit_user(string name);
	void delete_user(string name);
	void suspend_user(string name);
	void view_all_transactions();
	void edit_balance(string name);
};

