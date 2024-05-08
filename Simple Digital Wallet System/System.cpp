#pragma once
#include<assert.h>
#include <cassert>
#include"System.h"
#include <cryptopp/cryptlib.h>
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>

using namespace std;
using namespace CryptoPP;
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
void System::addUser(string& username, string& password, double balance) {
    if (allUsers.find(username) != allUsers.end()) {
        cout << "User '" << username << "' already exists." << endl;
    }
    else {

        User user(username, password, balance);
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
    string filename = "Transactions.txt";
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

string System::md5(const string& input)
{
    Weak::MD5 hash;
    string digest;

    StringSource(input, true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));

    return digest;
}

string System::SecureString()
{

    string password;
    char ch;
    while (true) {
        ch = _getch();
        if (ch == '\r' || ch == '\n') {
            cout << endl;
            break;
        }
        if (ch == '\b' && !password.empty()) {
            password.pop_back();
            cout << "\b \b";
        }
        else if (ch != '\b') {
            password += ch;
            cout << '*';
        }
    }
    return password;
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


void System::Register(string& username, string& password, double balance) {

    if (allUsers.find(username) != allUsers.end()) {
        cout << "User '" << username << "' already exists." << endl;
        cout << "please enter another username :\n";
        cin >> username;
        return Register(username, password, balance);
    }
    else {

        User user(username, md5(password), balance);
        allUsers[username] = user;
        cout << "User '" << username << "' registered successfully." << endl;


    }

}

bool System::Login(string username, string password) {
    auto it = allUsers.find(username);
    string chooice;
    if (it != allUsers.end() && it->second.Password == md5(password)) {
        loggedInUser = &(it->second);
        cout << "User '" << username << "' logged in successfully." << endl;
        return true;
    }
    else {
        cout << "Invalid username or email. Login failed.\npress 0 to exit and others to retry" << endl;
        cin >> chooice;
        if (chooice[0] == '0')
            return false;
        else
        {
            cout << "please enter your name : ";
            cin >> username;
            cout << "please enter your password : ";
            cin >> password;
            if (!System::Login(username, password))
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
