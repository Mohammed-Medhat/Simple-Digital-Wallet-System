#pragma once
#include<assert.h>
#include <cassert>
#include"System.h"

using namespace std;
map<string, User> System::allUsers;
vector<Transaction> System::allTransactions;
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
User* System::getUser(string& username) {
    auto it = allUsers.find(username);
    if (it != allUsers.end()) {
        return &(it->second);
    }
    else {
        cout << "User '" << username << "' not found." << endl;
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

void System::readUsersFromFile(const std::string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
        return;
    }

    // Clear existing users
    allUsers.clear();

    // Read user data from file
    std::string line;
    while (std::getline(file, line)) {
        // Parse user data from each line
        // Assuming user data is serialized in a format that can be deserialized
        User user = User::deserializeFromString(line);
        // Insert user into allUsers map
        allUsers[user.getUserName()] = user;
        cout << "readed\n";
    }

    file.close();
}

void System::writeUsersToFile(const string& filename)
{
    ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    // Write each user from allUsers map to file
    for (const auto& pair : allUsers) {
        const User& user = pair.second;
        std::string userData = user.serializeToString();
        file << userData << std::endl;
        cout << "added\n";
    }

    file.close();
}


void System::Register(string& username, string& password, double balance) {

    if (allUsers.find(username) != allUsers.end()) {
        cout << "User '" << username << "' already exists." << endl;
        cout << "please enter another username :\n";
        cin >> username;
        Register(username, password, balance);
    }
    else {
        User user(username, password, balance);
        allUsers[username] = user;
        cout << "User '" << username << "' registered successfully." << endl;


    }

}


bool System::Login(string username, string password) {
    auto it = allUsers.find(username);
    if (it != allUsers.end() && it->second.Password == password) {
        loggedInUser = &(it->second);
        cout << "User '" << username << "' logged in successfully." << endl;
        return true;
    }
    else {
        cout << "Invalid username or email. Login failed." << endl;
        return false;
    }
}
void System::Logout() {

    loggedInUser = nullptr;
    cout << "User logged out successfully." << endl;

}
System::~System(void) {

}