
#include<iostream>
#include"System.h"
#include "Admin.h"
#include"Transaction.h"
#include"User.h"
using namespace std;
System sys;
Admin aali("admin", "admin");
void home_page();
void user(User user) {
	bool done = true;
	while (done) {
		int choice, choice2;
		std::cout << "Welcome!" << std::endl;
		std::cout << "Please Enter :" << std::endl;
		std::cout << "1 - Send Money" << std::endl;
		std::cout << "2 - Request Money" << std::endl;
		cout << "3 - Check Requests \n";
		std::cout << "4 - Edit Username or Password" << std::endl;
		std::cout << "5 - View Current Balance" << std::endl;
		std::cout << "6 - View Transaction History" << std::endl;
		std::cout << "7 - Logout" << std::endl;
		cout << "8 - close app" << endl;
		std::cin >> choice;

		switch (choice) {
		case 1: {
			std::string name;
			double amount=-1;
			std::cout << "Please enter the recipient's username: ";
			std::cin >> name;
			while (amount <=0 ) {
				std::cout << "Please enter the amount of money: ";
				std::cin >> amount;
				if (amount<=0)
				{
					cout << "amount of money cannot = 0 or negative please try again\n ";
				}
			}
			System::loggedInUser->Send(name, amount);
			break;
		}
		case 2: {
			std::string name;
			double amount;
			std::cout << "Please enter the sender's username: ";
			std::cin >> name;
			std::cout << "Please enter the amount of money: ";
			std::cin >> amount;
			System::loggedInUser->RequestMoney(name, amount);
			break;
		}
		case 3:
			System::loggedInUser->viewPendingRequests();
			break;
		case 4: {
			bool valid_choice2 = true;
			while (valid_choice2) {
				std::cout << "Please choose:\n";
				std::cout << "1 - Edit Username\n";
				std::cout << "2 - Edit Password\n3 - Exit\n ";
				std::cin >> choice2;


				switch (choice2) {
				case 1: {

					//Admin::edit_username();
					break;
				}
				case 2: {
					std::string new_pass;
					std::cout << "Please enter your new password: ";
					std::cin >> new_pass;
					//Admin::edit_password();
					break;
				}
				case 3:

					break;
				default:
					std::cout << "Invalid input!" << std::endl;
					break;
				}
				if (choice2 == 3)
					break;
			}
			break;
		}
		case 5:
			std::cout << "Your current balance is: " << System::loggedInUser->ViewCurrentBalance() << std::endl;
			break;
		case 6:
			System::loggedInUser->ViewHistory();
			break;
		case 7:
			home_page(); // Assuming home_page() is a function to handle logout
			break;
		case 8:
			done = false;
			break;
		
		default:
			std::cout << "Invalid input!" << std::endl;
			break;
		}
		if (done == 0)
			break;
	}
}

void admin(Admin ali)
{
	int choice;
	cout << "\n\nPlease Enter :" << endl;
	cout << "1: to View all accounts data" << endl;
	cout << "2: to Edit account" << endl;
	cout << "3: to  Add a new user" << endl;
	cout << "4: to  Delete a user" << endl;
	cout << "5: to  Suspend an account" << endl;
	cout << "6: to  Reactivate an account" << endl;
	cout << "7: to  View all transactions" << endl;
	cout << "8: to  Edit admin account" << endl;
	cout << "9: to Logout" << endl;
	cout << "10: to Exit" << endl;

	bool valid_choice = true;
	while (valid_choice) {
		cin >> choice;

		switch (choice) {
		case 1:
		{
			ali.view_Accounts_Data();
			admin(aali);
			break;
		}
		case 2:
		{
			int choice1;
			cout << "1. Edit username" << endl;
			cout << "2. Edit password" << endl;
			cout << "3. Edit balance" << endl;
			cout << "4. Exit" << endl;

			cin >> choice1;

			switch (choice1) {
			case 1:
			{
				cout << "Please Enter The Username of The User to Edit his Username\n";
				string name;
				ali.edit_username(name);
				admin(aali);

				break;
			}
			case 2:
			{
				cout << "Please Enter The Username of The User to Edit his Password\n";
				string name;
				ali.edit_password(name);
				admin(aali);

				break;
			}
			case 3:
			{
				cout << "Please Enter The Username of The User to Edit his Balance\n";
				string name;
				cin >> name;
				ali.edit_balance(name);
				admin(aali);
			}
			case 4:
			{
				valid_choice = false; // Exit inner loop
				cout << "Exiting edit account menu..." << endl;
				admin(aali);
				break;
			}
			default:
			{
				cout << "Invalid choice. Please try again." << endl;
				admin(aali);
				break;
			}
			}
		}
		case 3:
		{
			ali.add_user();
			admin(aali);
			break;
		}
		case 4:
		{
			ali.delete_user();
			admin(aali);
			break;
		}
		case 5:
		{
			ali.suspend_user();
			admin(aali);
			break;
		}
		case 6:
		{
			ali.reactivated();
			admin(aali);
			break;
		}
		case 7:
		{
			ali.view_all_transactions();
			admin(aali);
			break;
		}
		case 8:
		{
			int choice2;
			cout << "1. Edit Admin username" << endl;
			cout << "2. Edit Admin password" << endl;
			cout << "3. Exit" << endl;

			cin >> choice2;

			switch (choice2)
			{
			case 1:
			{
				cout << "Please Enter The new Username of Admin :\t";
				string name;
				cin >> name;
				ali.set_username(name);
				cout << "the Username has Changed Sucssesfully \n";
				admin(aali);

				break;
			}
			case 2:
			{
				cout << "Please Enter The new password of Admin :\t";
				string pass;
				cin >> pass;
				ali.set_password(pass);
				cout << "the password has Changed Sucssesfully \n";
				admin(aali);


				break;
			}
			case 3:
			{
				valid_choice = false; // Exit inner loop
				cout << "Exiting edit account menu..." << endl;
				admin(aali);
				break;
			}
			default:
			{
				cout << "Invalid choice. Please try again." << endl;
				admin(aali);
				break;
			}
			break;
			}

			admin(aali);
			break;
		}
		case 9:
		{
			valid_choice = false; // Exit outer loop
			cout << "Admin loged out sucssesfully ! " << endl;
			home_page();
			break;
		}
		case 10:
		{
			valid_choice = false; // Exit outer loop
			cout << "Exiting admin menu..." << endl;
			break;
		}
		default:
		{
			cout << "Invalid choice. Please try again." << endl;
			admin(aali);
			break;
		}
		}
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
		cout << "please enter your name : ";
		cin >> name;
		cout << "please enter your password : ";
		cin >> password;
		if(sys.Login(name, password))
		user(sys.allUsers[name]);
		break;
	}
	case 2: {
		cout << "please enter your name : ";
		cin >> name;
		cout << "please enter your password : ";
		cin >> password;

		if (name=="admin"&&password=="admin")
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

		cout << "please enter your name : ";
		cin >> name;
		cout << "please enter your password : ";
		cin >> password;
		cout << "please enter your balance : ";
		//sys.Register(name, password, balance);
		break;
	}
	case 4:
	{
		return;
		break;
	}
	default: {
		cout << "invalid choice\n";
		home_page();
	}

	}

}


void main() {
	
	System::readUsersFromFile(); 
	System::readAllTransactions();
	string x = "a7a";
	string y = "messi";

	System::addUser(x, x, 1000);
	System::addUser(y, y, 1000);
	for(Transaction &t:System::allTransactions)
	{
		// Get sender and receiver from the transaction
		std::string senderName = t.getSender();
		std::string receiverName = t.getReciever();

		// Get sender user from the system
		User* sender = System::getUser(senderName);
		if (sender == nullptr) {
			
			continue; // Skip to the next transaction
		}

		// Get receiver user from the system
		User* receiver = System::getUser(receiverName);
		if (receiver == nullptr) {
			
			continue; // Skip to the next transaction
		}

		// Add transaction to sender's and receiver's history
		sender->addTransactionToHistory(t);
		receiver->addTransactionToHistory(t);
	
	}

	home_page();
	

	System::writeAllTransactions();
	System::writeUsersToFile();
}
