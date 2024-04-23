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



map<std::string, User> System::loadUsersFromFile(const std::string& filename)
{
    std::map<std::string, User> users;
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Error: Failed to open file for reading." << std::endl;
        return users;
    }

    std::string line;
    while (std::getline(ifs, line)) {
        size_t pos = line.find(':');
        if (pos != std::string::npos) {
            std::string username = line.substr(0, pos);
            User user;
            user.deserialize(ifs);
            users[username] = user;
        }
    }

    ifs.close();
    return users;
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