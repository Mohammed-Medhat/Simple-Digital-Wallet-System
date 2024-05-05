#pragma once
#include<assert.h>
#include <cassert>
#include"System.h"

using namespace std;
map<string, User> System::allUsers;
vector<Transaction> System::allTransactions;
User* System::loggedInUser;
vector<Transaction>System::allPendingRequests;
System::System() {

}
void System::addnewUser(string& username) {
    if (allUsers.find(username) != allUsers.end()) {
        cout << "User '" << username << "' already exists." << endl;
    }
    else {
        cout << "add password" << endl;
        string password;
        cin >> password;
        User user(username, password, 0);
        allUsers[username] = user;
        cout << "User '" << username << "' added successfully." << endl;
    }


}


void System::removeUser(string& username)
{
    auto it = allUsers.find(username);
    if (it != allUsers.end()) {
        allUsers.erase(it);
        cout << "User '" << username << "' removed successfully." << endl;
    }
    else {
        cout << "User '" << username << "' not found." << endl;
    }
}
User* System::getUser(string username) {
    auto it = allUsers.find(username);
    if (it != allUsers.end()) {
        return &(it->second);
    }
    else {
        cout << "User '" << username << "' not found." << endl;
        return nullptr;
    }
}
User* System::getUserForTrans(string username) {
    auto it = allUsers.find(username);
    if (it != allUsers.end()) {
        return &(it->second);
    }
    else {
  
        return nullptr;
    }
}
void System::showAllUser() {
    cout << "All usernames:" << endl;
    for (const auto& pair : allUsers) {
        cout << pair.first << endl;
    }
}

bool System::search_user(string username)
{
    map<string, User>::iterator it;
     it = allUsers.find(username);
    if (it != allUsers.end()) {
        return true;
    }
    else {
        return false;
    }
}

void System::readAllTransactions()
{
    string filename ="Transactions.txt" ;
    // Open the file for reading
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for reading." << endl;
        return;
    }

    allTransactions.clear(); // Clear existing transactions before reading new ones

    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            try {
                // Deserialize each line into a Transaction object and add to vector
                Transaction transaction = Transaction::deserializeFromString(line);
                allTransactions.push_back(transaction);
            }
            catch (const exception& e) {
                cerr << "Error reading transaction: " << e.what() << endl;
            }
        }
    }

    inFile.close();
}

void System::writeAllTransactions()
{
    string filename = "Transactions.txt";
    // Open the file for writing
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& transaction : allTransactions) {
        // Serialize the transaction to string and write to file
        string serializedTransaction = transaction.serializeToString();
        if (!serializedTransaction.empty()) {
            outFile << serializedTransaction << endl;
        }
    }

    outFile.close();
}

void System::writePendingRequests()
{
    string filename = "PendingRequest.txt";
    // Open the file for writing
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (const auto& transaction : allPendingRequests) {
        // Serialize the transaction to string and write to file
        string serializedTransaction = transaction.serializeToString();
        if (!serializedTransaction.empty()) {
            outFile << serializedTransaction << endl;
        }
    }

    outFile.close();
}

void System::readPendingRequests()
{
    string filename = "PendingRequest.txt";
    // Open the file for reading
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for reading." << endl;
        return;
    }

    allPendingRequests.clear(); // Clear existing transactions before reading new ones

    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            try {
                // Deserialize each line into a Transaction object and add to vector
                Transaction transaction = Transaction::deserializeFromString(line);
                allPendingRequests.push_back(transaction);
            }
            catch (const exception& e) {
                cerr << "Error reading transaction: " << e.what() << endl;
            }
        }
    }

    inFile.close();

}


void System::readUsersFromFile()
{
    string filename = "Users.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for reading." << endl;
        return;
    }

    // Clear existing users
    allUsers.clear();

    // Read user data from file
    string line;
    while (getline(file, line)) {
        try {
            User user = User::deserializeFromString(line);
            allUsers[user.getUserName()] = user;
           // cout << "Read user: " << user.getUserName() << endl;
        }
        catch (const exception& e) {
           // cerr << "Error reading user from file: " << e.what() << endl;
        }
    }

    file.close();
}

void System::writeUsersToFile()
{
    string filename = "Users.txt";
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    // Write each user from allUsers map to file
    for (const auto& pair : allUsers) {
        const User& user = pair.second;
        string userData = user.serializeToString();
        file << userData << endl;
        //cout << "added\n";
    }

    file.close();
}

void System::editeUser()
{
    int choice;
    bool valid_choice2 = true;
    while (valid_choice2) {
        cout << "Please choose:\n";
        cout << "1 - Edit Username\n";
        cout << "2 - Edit Password\n3 - Exit\n ";
        cin >> choice;


        switch (choice) {
        case 1: {

            System::loggedInUser->editUsername();
            break;
        }
        case 2: {

            System::loggedInUser->editPassword();
            break;
        }
        case 3:

            break;
        default:
            cout << "Invalid input!" << endl;
            break;
        }
        if (choice == 3)
            break;
    }
}


bool System::Register() {
    string username;
    
    
    
    cout << "please enter Username :\n";
    cin >> username;

    if (allUsers.find(username) != allUsers.end()) {
        cout << "Username already exist \n";
        return Register();
    }
    else {
        string password;
        cout << "Enter password :";
        cin >> password;
        User user(username, password, 0);
        allUsers[username] = user;
        cout << "User '" << username << "' registered successfully." << endl;
        System::loggedInUser = &System::allUsers[username];
        return true;
    }

}


bool System::Login() {
    string username;
    string password;
    cout << "please enter your name : ";
    cin >> username;
    cout << "please enter your password : ";
    cin >> password;



    auto it = allUsers.find(username);
    string chooice;
    if (it != allUsers.end() && it->second.Password == password) {
        loggedInUser = &(it->second);
        cout << "User '" << username << "' logged in successfully." << endl;
        return true;
    }
    else {
        cout << "Invalid username or email. Login failed.\npress 0 to exit and others to retry" << endl;
        cin >> chooice;
        if(chooice == "0"&& chooice.length()==1)
        return false;
        else
        {
            if(!System::Login())
                return false;
        }
    }
}
void System::Logout() {

    loggedInUser = nullptr;
    cout << "User logged out successfully." << endl;

}
System::~System(void) {

}