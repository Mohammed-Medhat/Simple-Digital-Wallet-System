#include<iostream>
#include"System.cpp"

using namespace std;

int main() {
	User u("dsa", "sda", 50);
	System s;
	Node* x=s.finduser("dsa", "sda");
	cout << x->value->getUserName();




}
