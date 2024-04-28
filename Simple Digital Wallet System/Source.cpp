
#include<iostream>
#include"System.h"
#include "Admin.h"
#include"Transaction.h"
#include"User.h"
using namespace std;
System sys;
Admin aali("admin", "admin");
void home_page();
void admin(Admin admin);
void user(User user) {
	bool done = true;
	while (done) {
		int choice, choice2;
		cout << "Welcome!" << endl;
		cout << "Please Enter :" << endl;
		cout << "1 - Send Money" << endl;
		cout << "2 - Request Money" << endl;
		cout << "3 - Check Requests \n";
		cout << "4 - Edit Username or Password" << endl;
		cout << "5 - View Current Balance" << endl;
		cout << "6 - View Transaction History" << endl;
		cout << "7 - Logout" << endl;
		cout << "8 - close app" << endl;
		cin >> choice;

		switch (choice) {
		case 1: {
			string name;
			double amount=-1;
			cout << "Please enter the recipient's username: ";
			cin >> name;
			while (amount <=0 ) {
				cout << "Please enter the amount of money: ";
				cin >> amount;
				if (amount<=0)
				{
					cout << "amount of money cannot = 0 or negative please try again\n ";
				}
			}
			System::loggedInUser->Send(name, amount);
			break;
		}
		case 2: {
			string name;
			double amount;
			cout << "Please enter the sender's username: ";
			cin >> name;
			cout << "Please enter the amount of money: ";
			cin >> amount;
			System::loggedInUser->RequestMoney(name, amount);
			break;
		}
		case 3:
			System::loggedInUser->viewPendingRequests();
			break;
		case 4: {
			bool valid_choice2 = true;
			while (valid_choice2) {
				cout << "Please choose:\n";
				cout << "1 - Edit Username\n";
				cout << "2 - Edit Password\n3 - Exit\n ";
				cin >> choice2;


				switch (choice2) {
				case 1: {

					Admin::edit_username();
					break;
				}
				case 2: {
					string new_pass;
					cout << "Please enter your new password: ";
					cin >> new_pass;
					Admin::edit_password();
					break;
				}
				case 3:

					break;
				default:
					cout << "Invalid input!" << endl;
					break;
				}
				if (choice2 == 3)
					break;
			}
			break;
		}
		case 5:
			cout << "Your current balance is: " << System::loggedInUser->ViewCurrentBalance() << endl;
			break;
		case 6:
			System::loggedInUser->ViewHistory();
			break;
		case 7:
			home_page(); // Assuming home_page() is a function to handle logout
			break;
		case 8:
			return;
			break;
		
		default:
			cout << "Invalid input!" << endl;
			break;
		}
		if (done == 0)
			break;
	}
}

void admin(Admin admin) {
	int choice;
	cout << "Please Enter:" << endl;
	cout << "1. View all accounts data" << endl;
	cout << "2. Edit account" << endl;
	cout << "3. Add a new user" << endl;
	cout << "4. Delete a user" << endl;
	cout << "5. Suspend an account" << endl;
	cout << "6. Reactivate an account" << endl;
	cout << "7. View all transactions" << endl;
	cout << "8. Edit admin account" << endl;
	cout << "9. Exit" << endl;

	bool valid_choice = true;
	while (valid_choice) {
		cin >> choice;

		switch (choice) {
		case 1:
			admin.view_Accounts_Data();
			break;
		case 2:
			int choice1;
			cout << "1. Edit username" << endl;
			cout << "2. Edit password" << endl;
			cout << "3. Edit balance" << endl;
			cout << "4. Exit" << endl;

			cin >> choice1;

			switch (choice1) {
			case 1:
			{
				string new_name; // Declare new_name inside the case block
				cout << "Please enter the new name: ";
				cin >> new_name;
				admin.set_username(new_name);
			}
			break;
			case 2:
			{
				string new_password; // Declare new_password inside the case block
				cout << "Please enter the new password: ";
				cin >> new_password;
				admin.set_password(new_password);
			}
			break;
			case 3:
				valid_choice = false; // Exit inner loop
				cout << "Exiting edit account menu..." << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
			}
			break;
		case 3:
			admin.add_user();
			break;
		case 4:
			admin.delete_user();
			break;
		case 5:
			admin.suspend_user();
			break;
		case 6:
			admin.reactivated();
			break;
		case 7:
			admin.view_all_transactions();
			break;
		case 8:
			// Implement admin account editing functionality
			break;
		case 9:
			valid_choice = false; // Exit outer loop
			cout << "Exiting admin menu..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}
}


void home_page() {

	int choice;
	cout << "Welcome!" << endl;
	cout << "Please Enter : " << endl;
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
		cout << "invalid choice";
		home_page();
	}

	}

}


void main() {
	
	System::readUsersFromFile(); 
	System::readAllTransactions();
	
	for(Transaction &t:System::allTransactions)
	{
		// Get sender and receiver from the transaction
		string senderName = t.getSender();
		string receiverName = t.getReciever();

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
