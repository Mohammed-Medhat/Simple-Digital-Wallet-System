#pragma once
#include<iostream>
#include"System.h"
#include "Admin.h"
#include"Transaction.h"
#include"User.h"
using namespace std;
System sys;
Admin aali("admin", "admin");
void home_page();
void admin(Admin ali);
void user(User ali)
{
	int choice, choice2;
	cout << "Welcome!" << endl;
	cout << "Please Enter : " << endl;
	cout << "1-for Sending Money" << endl;
	cout << "2-for Requesting Money" << endl;
	cout << "3-for Editing Username or Password" << endl;
	cout << "4-for viewing your current balance" << endl;
	cout << "5-for viewing your transaction history" << endl;
	cout << "6-to logout from account" << endl;
	cin >> choice;
	if (choice == 1)
	{
		string name;
		double amount;
		cout << "please enter the username of the recipient's username :\t";
		cin >> name;
		cout << "please enter the amount of money :\t";
		cin >> amount;
		ali.Send(name, amount);
	}
	else if (choice == 2)
	{
		string name;
		double amount;
		cout << "please enter the username of the sender :\t";
		cin >> name;
		cout << "please enter the amount of money :\t";
		cin >> amount;
		ali.Send(name, amount);
	}
	else if (choice == 3)
	{
		string new_name, new_pass;

		cout << "please enter :\n" << "1-for editing username\n" << "2-for editing password\n";
		cin >> choice2;
		if (choice2 == 1)
		{
			cout << "please enter your new username :\n";
			cin >> new_name;
			//ali.edit_name
		}
		else if (choice2 == 2)
		{
			cout << "please enter your new password :\n";
			cin >> new_pass;
			//ali.edit_pass
		}
		else
		{
			cout << "invalid input !!\n";
			user(ali);
		}
	}
	else if (choice == 4)
	{
		cout << "your current balance is :\n" << ali.ViewCurrentBalance();
	}
	else if (choice == 5)
	{
		ali.ViewHistory();
	}
	else if (choice == 6)
	{
		home_page();
	}
	else
	{
		cout << "Invallid input !!\n";
		user(ali);
	}
}
void admin(Admin ali) {
	int choice;
	cout << "please Enter :" << endl;
	cout << "1- for View all accounts data  " << endl;
	cout << "2- for editing account  " << endl;
	cout << "3- for adding a new user" << endl;
	cout << "4- for deleting new user   " << endl;
	cout << "5- for suspending an account  " << endl;
	cout << "6- for reactivating an account " << endl;
	cout << "7- view all transactions  " << endl;
	cout << "8- edit admin account  " << endl;
	cout << "9- for exit!";
	cin >> choice;
	if (choice == 1) {
		ali.view_Accounts_Data();
	}
	else if (choice == 2) {
		int choice1;
		cout << "1- for editing user name  " << endl;
		cout << "2- for editing password  " << endl;
		cout << "3- for editing balance" << endl;
		cin >> choice1;
		if (choice1 == 1) {
			ali.edit_username();
		}
		else if (choice1 == 2) {
			ali.edit_password();
		}
		else if (choice1 == 3) {
			ali.edit_balance();
		}
	}
	else if (choice == 3)
	{
		ali.add_user();

	}
	else if (choice == 4) {
		ali.delete_user();
	}
	else if (choice == 5) {
		ali.suspend_user();
	}
	else if (choice == 6) {
		ali.reactivated();
	}
	else if (choice == 7) {
		ali.view_all_transactions();
	}
	else if (choice == 8) {
		int choice2;
		string new_name, new_password;
		cout << "1- for editing user name  " << endl;

		cout << "2- for editing password  " << endl;
		cin >> choice2;
		if (choice2 == 1) {
			cout << "please enter the new name: ";
			cin >> new_name;
			ali.set_username(new_name);
		}
		else if (choice2 == 2) {
			cout << "please enter the new password";
			cin >> new_password;
			ali.set_password(new_password);
		}
	}
	else if (choice == 9) {
		home_page();
	}
	else {
		cout << "invalid choice!!!";
		admin(ali);
	}
}
void home_page() {

	int choice;
	cout << "Welcome!" << endl;
	cout << "Pleaes Enter : " << endl;
	cout << "1-to Log-in as User" << endl;
	cout << "2-to Log-in as Admin" << endl;
	cout << "3-for Registering" << endl;
	cout << "4-to Exit" << endl;

	cin >> choice;
	string name, password;
	switch (choice) {
	case 1:
	{
		cout << "please enter your name";
		cin >> name;
		cout << "please enter your password";
		cin >> password;
		sys.Login(name, password);
		user(sys.allUsers[name]);
		break;
	}
	case 2: {
		cout << "please enter your name";
		cin >> name;
		cout << "please enter your password";
		cin >> password;

		if (sys.Login(name, password))
		{
			admin(aali);
		}
		else
		{
			home_page();
		}
		break;
	}
	case 3: {

		cout << "please enter your name";
		cin >> name;
		cout << "please enter your password";
		cin >> password;
		cout << "please enter your balance";
		//sys.Register(name, password, balance);
		break;
	}
	case 4:
	{
		return;
		break;
	}
	default: {
		cout << "invalid choice";
		home_page();
	}

	}

}


void main() {
	System sys;
	sys.readUsersFromFile(); // Load users data from file
	DATE d;
	d.day=15;
	d.month=2;
	d.hour=6;
	d.min=30; d.year=2024;
	Transaction ts("alii","aliii",20,d);
	sys.allTransactions.push_back(ts);
	sys.readUsersFromFile();

	Transaction x =sys.allTransactions[0];
	cout<<x.sender;


	sys.writeAllTransactions();

	
	// Create and add users to the system
	//User ali("ali", "1234567", 1200);
	//User zoz("alii", "1234568", 1200);
	//User lol("aliii", "1234569", 1200);
	//User loll("aliiii", "12345691", 1200);
	
	//// Add users to the system
	//sys.allUsers[ali.getUserName()] = ali;
	//sys.allUsers[zoz.getUserName()] = zoz;
	//sys.allUsers[lol.getUserName()] = lol;
	//sys.allUsers[loll.getUserName()] = loll;

	sys.writeUsersToFile();
	
	
	//home_page();
}
