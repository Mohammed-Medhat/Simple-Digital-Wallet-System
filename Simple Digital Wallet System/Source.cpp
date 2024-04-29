
#include<iostream>
#include"System.h"
#include "Admin.h"
#include"Transaction.h"
#include"User.h"
using namespace std;
System sys;
Admin aali("admin", "admin");
void home_page();
void user(User &user) {
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

					System::loggedInUser->editUsername();
					break;
				}	
				case 2: {
					std::string new_pass;
					std::cout << "Please enter your new password: ";
					std::cin >> new_pass;
					System::loggedInUser->editPassword();
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

void admin(Admin &ali)
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
				cin >> name;
				ali.edit_username(name);
				return admin(aali);

				break;
			}
			case 2:
			{
				cout << "Please Enter The Username of The User to Edit his Password\n";
				string name;
				cin >> name;
				ali.edit_password(name);
				return admin(aali);

				break;
			}
			case 3:
			{
				cout << "Please Enter The Username of The User to Edit his Balance\n";
				string name;
				cin >> name;
				ali.edit_balance(name);
				return admin(aali);
			}
			case 4:
			{
				valid_choice = false; // Exit inner loop
				cout << "Exiting edit account menu..." << endl;
				return admin(aali);
				break;
			}
			default:
			{
				cout << "Invalid choice. Please try again." << endl;
				return admin(aali);
				break;
			}
			}
		}
		case 3:
		{
			ali.add_user();
			return admin(aali);
			break;
		}
		case 4:
		{
			ali.delete_user();
			return admin(aali);
			break;
		}
		case 5:
		{
			ali.suspend_user();
			return admin(aali);
			
		}
		case 6:
		{
			ali.reactivated();
			return admin(aali);
		}
		case 7:
		{
			ali.view_all_transactions();
			return admin(aali);
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
				return admin(aali);

				break;
			}
			case 2:
			{
				cout << "Please Enter The new password of Admin :\t";
				string pass;
				cin >> pass;
				ali.set_password(pass);
				cout << "the password has Changed Sucssesfully \n";
				return admin(aali);


				break;
			}
			case 3:
			{
				valid_choice = false; // Exit inner loop
				cout << "Exiting edit account menu..." << endl;
				return admin(aali);
				break;
			}
			default:
			{
				cout << "Invalid choice. Please try again." << endl;
				return admin(aali);
				break;
			}
			break;
			}

			return admin(aali);
			break;
		}
		case 9:
		{
			valid_choice = false; // Exit outer loop
			cout << "Admin loged out sucssesfully ! " << endl;
			return home_page();
			break;
		}
		case 10:
		{
			valid_choice = false; // Exit outer loop
			cout << "Exiting admin menu..." << endl;
			return home_page();
			break;
		}
		default:
		{
			cout << "Invalid choice. Please try again." << endl;
			return admin(aali);
			break;
		}
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
			cout << "invalid username or password please try again !\n\n";
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
	System::readPendingRequests();
	for(Transaction &t:System::allTransactions)
	{
		 Get sender and receiver from the transaction
		string senderName = t.getSender();
		string receiverName = t.getReciever();

		 Get sender user from the system
		User* sender = System::getUserForTrans(senderName);
		if (sender == nullptr) {
			
			continue; // Skip to the next transaction
		}

		 Get receiver user from the system
		User* receiver = System::getUserForTrans(receiverName);
		if (receiver == nullptr) {
			
			continue; // Skip to the next transaction
		}

		 Add transaction to sender's and receiver's history
		sender->addTransactionToHistory(t);
		receiver->addTransactionToHistory(t);
	
	}
	for (Transaction& t : System::allPendingRequests)
	{
		// Get sender and receiver from the transaction
		string senderName = t.getSender();
		string receiverName = t.getReciever();

		// Get sender user from the system
		User* sender = System::getUserForTrans(senderName);
		if (sender == nullptr) {

			continue; // Skip to the next transaction
		}

		// Get receiver user from the system
		User* receiver = System::getUserForTrans(receiverName);
		if (receiver == nullptr) {

			continue; // Skip to the next transaction
		}

		// Add transaction to sender's and receiver's history
		sender->addPendingRequest(t);
		//receiver->addTransactionToHistory(t);

	}

	home_page();
	
	System::writePendingRequests();
	System::writeAllTransactions();
	System::writeUsersToFile();
}
