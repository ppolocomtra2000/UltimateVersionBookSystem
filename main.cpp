#include "Library.h"
#include "Log.h"
#include "Book.h"
#include "User.h"
#include "Staff.h"
#include "Admin.h"
#include "Customer.h"
#include "Password.h"

Log rec;
Library lib;
Password pass;
string account;
//get user's status
int login(string username, string password)
{
	for (int i = 0; i < lib.userList.size(); i++)
	{
		if (username == lib.userList[i].getUsername() && password == lib.userList[i].getPassword())
			return lib.userList[i].getStatus();
	}
	return 0;
}

void loadData()
{
	lib.loadBook();
	lib.loadCash();
	lib.loadUser();
}

void welcome()
{
	system("cls");
	int status = 0;
	int time = 0;
	cout << "Welcome to NTT Book Store Management System " << endl;
	cout << "Please login first" << endl;
	while (status == 0)
	{
		string tempPass;
		cout << "Username: " << endl;
		cin >> account;
		cout << "Password:" << endl;
		cin >> tempPass;
		pass.setPassword(tempPass);
		status = login(account, pass.getPassword());
		if (status < 1 || status>5)
		{
			time++;
			if (time < 3)
				cout << "Login fail! Please try again" << endl;
			else if (time < 4)
				cout << "Are you remember password?" << endl;
			else if (time < 5)
				cout << "Give you the last chance" << endl;
			else
			{
				cout << "Maybe you should register a new account" << endl;
				Sleep(1500);
				return;
			}
			Sleep(1500);
		}
		else {
			if (status == 1)
			{
				Publisher man;
				man.Interface(account);
			}
			else if (status == 2)
			{
				Author man;
				man.Interface(account);
			}
			else if (status == 3)
			{
				Customer man;
				man.Interface(account);
			}
			else if (status == 5)
			{
				Admin man;
				man.Interface(account);
			}
			break;
		}
		system("cls");
		cout << "Welcome to NTT Book Store Management System " << endl;
		cout << "Please login first" << endl;
	}
}

int main()
{
	loadData();
	welcome();
	return 0;
}