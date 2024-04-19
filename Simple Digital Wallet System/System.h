
#include <vector>
#include "User.h"
#include<map>

using namespace std;


class System
{
private:
	map<string, User> allUsers;
	User* loggedInUser=NULL;
	
	
public:
	System();
	void addnewUser(string&, string&);
	void addUser(string&, string&,string&, float );
	void removeUser(const string& );
	User* getUser(const string& username);
	bool Login(string , string );
	void Register(string& , string& , string& );
	void Logout();
	void showAllUser();
	//void saveData();
	//void deleteData();
	~System();
};
