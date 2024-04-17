#include "System.h"
#include"User.h"
#include<iostream>

System::System() {

 }

Node *System::finduser(string username, string password)
{
	Node *temp = allUsers;
	while (temp != NULL)
	{
		if (temp->value->getUserName() == username && temp->value->getPassword() == password)
		{
			return temp;
		}
		else if (temp->value->getUserName() < username)
		{
			//right
			temp = temp->right;
		}
		else
		{
			//left
			temp = temp->left;
		}
	}

	return temp;
	
}
void System::Login(string username,string password ) {

}
bool System::isExist(string username, string password) {
	

	
}
System::System() {

}
