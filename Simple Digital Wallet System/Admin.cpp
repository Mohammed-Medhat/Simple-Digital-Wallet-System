#pragma once

#include "Admin.h"
using namespace std;

map<string, User> Admin::suspended_users;
Admin::Admin()
{
	username = "admin";
	password = "admin";
}

Admin::Admin(string name, string pass)
{
	username = name;
	password = pass;
}


void Admin::set_username(string new_name)
{
	username = new_name;
}

string Admin::get_username()
{
	return this->username;
}

void Admin::set_password(string new_pass)
{
	password = new_pass;
}

string Admin::get_password()
{
	return this->password;
}



void Admin::view_Accounts_Data()
{
	map<string, User>::iterator it;

	for (it = System::allUsers.begin(); it != System::allUsers.end(); it++)
	{
		it->second.userData();
	}
}

void Admin::edit_username()
{
	string name, new_name;
	cout << "Please Enter The Username of the User to Edit His Username:\t";
	cin >> name;
	
	do
	{
		
			cout << "Please Enter The New Username :\t";
			cin >> new_name;
			if (!System::search_user(new_name))
				break;
			else
			{
				cout << "username is already in use" << endl;
			}
		//check the new name is valid
	} while (System::search_user(new_name));
		System::allUsers[name].setUserName(new_name);
		cout << "The Username Has Been Changed Successfully \n";
		cout << "The new Username of The User is:\t" << new_name << "\n";
	
	
}

void Admin::edit_password()
{
	string name, new_pass;
	cout << "Please Enter The Username of the User to Edit His Password :\t";
	cin >> name;

	//check the name fun

	cout << "Please Enter The New Password :\t";
	cin >> new_pass;
	//check the new pass is valid

	System::allUsers[name].setpassword(new_pass);
	cout << "The Password Has Been Changed Successfully \n";
	cout << "The new Password of The User is :\t" << new_pass << "\n";
}

void Admin::add_user()
{
	string username;

	cout << "Please Enter The Username of The User :\t";

	cin >> username;

	
		cout << "Please Enter The Username of The User :\n";
		string password;
		cin >> password;
		double balance;
		cout << "Please Enter The Username of The User :\n";
		cin >> balance;
		System::Register(username, password, balance);
}

void Admin::delete_user()
{
	string name;

	cout << "Please Enter The Username of the User You Want to Delete :\t";

	cin >> name;
	//check the username func
	System::allUsers.erase(name);
	cout << "The User Has Been Deleted Successfully\n";
}

void Admin::suspend_user()
{
	string name;

	cout << "Please Enter The Username of the User You Want to Suspend :\t";

	cin >> name;
	//check the username func

	suspended_users[name] = System::allUsers[name];

	cout << "The User Has Been Suspended Successfully\n";

}

void Admin::reactivated()
{
	string name;

	cout << "Please Enter The Username of The User You Want to Reactivate :\t";

	cin >> name;
	//check the username func
	//check if its suspended
	suspended_users.erase(name);
	cout << "The User Has Been Reactivated Successfully\n";
}

void Admin::view_all_transactions()
{
	vector<Transaction>::iterator it;

	it = System::allTransactions.begin();


	for(Transaction t : System::allTransactions)
	{
		t.DisplayTransactionData();
	}

}

void Admin::edit_balance()
{
	string name;
	double new_balance;
	cout << "Please Enter The Username of The User You Want to Edit His Balance :\t";

	cin >> name;

	cout << "Please Enter The Nem Balance :\t";
	//check the username func
	cin >> new_balance;

	System::allUsers[name].setbalance(new_balance);

	cout << "The User Balance Has Been Modified \n";

}



Admin::~Admin(void)
{
}
