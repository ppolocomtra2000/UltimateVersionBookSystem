#include "Admin.h"

extern Log rec;
extern Library lib;
extern string account;

void Admin::addUser(){
	system("cls");
	User newUser;
	string name, pass;
	int newStatus;
	//register
	cout << "Username:" << endl;
	cin >> name;
	for (int i = 0; i < lib.userList.size(); i++)
	{
		if (name == lib.userList[i].getUsername())
		{
			if (lib.userList[i].getStatus() != 0)
			{
				cout << "User  already exist!" << endl;
				Sleep(1000);
				return;
			}
			//user already in userList but status =0 
			else
			{
				cout << "Password:" << endl;
				cin >> pass;
				lib.userList[i].setUsername(name);
				lib.userList[i].setPassword(pass);
				cout << "Which position do you want to create? ( 3 for Customer, 2 for Author, 1 for Publisher )" << endl;
				cin >> newStatus;
				lib.userList[i].setStatus(newStatus); 
				cout << "Add user successfully!" << endl;
				Sleep(1000);
				rec.userLog(account, name, "add", 0);
				User::printAllUser();
				return;
			}
		}
	}
	//user has not in userList yet
	cout << "Password:" << endl;
	cin >> pass;
	newUser.setPassword(pass);
	newUser.setUsername(name);
	cout << "Which position do you want to create? ( 3 for Customer, 2 for Author, 1 for Publisher )" << endl;
	cin >> newStatus;
	newUser.setStatus(newStatus); // customer
	lib.userList.push_back(newUser);
	cout << "Add user successfully!" << endl;
	Sleep(1000);
	rec.userLog(account, name, "add", 0);
	Staff::printAllUser();
}

void Admin::delUser()
{
	system("cls");
	int choice;
	string name;
	cout << "Username you want to delete: " << endl;
	cin >> name;
	for (int i = 0; i < lib.userList.size(); i++)
	{
		if (lib.userList[i].getUsername() == name)
		{
			//already exist
			if (lib.userList[i].getStatus() != 0)
			{
				cout << "Are you sure? ( 1 for YES 0 for NO )" << endl;
				cin >> choice;
				if (choice == 1)
				{
					lib.userList[i].setStatus(0);
					cout << "Delete successfully!" << endl;
				}
				else
					cout << "Delete canceled." << endl;
				Sleep(1000);
				rec.userLog(account, name, "del", 0);
				Staff::printAllUser();
				return;
			}
		}
	}
	cout << "User not exist!" << endl;
	Sleep(1000);
}

void Admin::setUser() // update postion
{
	system("cls");
	int choice;
	string name;
	cout << "Please enter the username you want to change status" << endl;
	cin >> name;
	for (int i = 0; i < lib.userList.size(); i++)
	{
		if (name == lib.userList[i].getUsername()) {
			if (lib.userList[i].getStatus() != 0)
			{
				cout << "Please input a number: 3 for Customer, 2 for Author, 1 for Publisher, 0 for quit" << endl;
				cin >> choice;
				if (choice != 0)
				{
					lib.userList[i].setStatus(choice);
					cout << "Change user status successfully!" << endl;
				}
				else
					cout << "Change canceled." << endl;
				Sleep(1000);
				rec.userLog(account, name, "set", choice);
				Staff::printAllUser();
				return;
			}
		}
	}
	cout << "User not exist!" << endl;
	Sleep(1000);
}

void Admin::listUser()
{
	system("cls");
	string temp;
	vector<string> statusOfUser;
	temp = "Admin";
	statusOfUser.push_back(temp);
	temp = "Author";
	statusOfUser.push_back(temp);
	temp = "Publisher";
	statusOfUser.push_back(temp);
	temp = "Customer";
	statusOfUser.push_back(temp);
	cout << "This is the list of all user:" << endl;
	cout << "------------------------------" << endl;
	cout << "Username\tPassword\tStatus" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < lib.userList.size(); i++)
	{
		if (lib.userList[i].getStatus() != 0)
		{
			cout << lib.userList[i].getUsername() << "\t" << lib.userList[i].getPassword() << "\t" << lib.userList[i].getStatus() << endl;
		}
	}
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
}

void Admin::Interface(string username)
{
	int choice;
	while (1)
	{
		system("cls");
		cout << "Welcome " << username << ".You are administrator" << endl;
		cout << "Please choose what you want to do by input a number" << endl;
		while (1)
		{
			cout << "1. Add new user" << endl;
			cout << "2. Delete user" << endl;
			cout << "3. Change user privilage" << endl;
			cout << "4. Add new book" << endl;
			cout << "5. Delete book" << endl;
			cout << "6. Change book's inforamation" << endl;
			cout << "7. List book ( all )" << endl;
			cout << "8. List book ( by Name)" << endl;
			cout << "9. List book ( by author name )" << endl;
			cout << "10. List book ( by publisher name )" << endl;
			cout << "11. List all user's information" << endl;
			cout << "12. Look up net profit" << endl;
			cout << "13. Change my password" << endl;
			cout << "0. Exit" << endl;
			cin >> choice;
			if (choice < 0 || choice >13)
				cout << "Again" << endl;
			else break;
		}
		switch (choice)
		{
		case 1:
			addUser();
			break;
		case 2:
			delUser();
			break;
		case 3:
			setUser();
			break;
		case 4:
			Staff::addBook();
			break;
		case 5:
			Staff::delBook();
			break;
		case 6:
			Staff::setBook();
			break;
		case 7:
			Staff::listBookAll();
			break;
		case 8:
			Staff::listBookByName();
			break;
		case 9:
			outAuthorList();
			break;
		case 10:
			outPublisherList();
			break;
		case 11:
			listUser();
			break;
		case 12:
			Staff::viewProfit();
			break;
		case 13:
			Staff::changePassword();
			break;
		case 0:
			exit(0);
		}
	}
}