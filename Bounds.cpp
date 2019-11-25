#include "Bounds.h"

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
		cout << "Username: " << endl;
		cin >> account;
		pass.inputPassword();
		status = login(account, pass.getPassword());
		if (status < 1 || status>3)
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
				Admin man;
				man.Interface(account);
			}
			else if (status == 2)
			{
				Staff man;
				man.Interface(account);
			}
			else if (status == 3)
			{
				Staff man;
				man.Interface(account);
			}
			break;
		}
		system("cls");
		cout << "Welcome to NTT Book Store Management System " << endl;
		cout << "Please login first" << endl;
	}
}