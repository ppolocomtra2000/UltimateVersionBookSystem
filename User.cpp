#include "User.h"
#include "Library.h"

extern Log rec;
extern Library lib;
extern string account;

void User::printAllUser()
{
	ofstream fout;
	fout.open("User.txt");
	if (!fout)
	{
		cerr << "User.txt can't open" << endl;
		exit(0);
	}
	fout  << lib.userList[0].getUsername() << " " << lib.userList[0].getPassword() << " " << lib.userList[0].getStatus();
	for (int i = 1; i < lib.userList.size(); i++)
	{
		fout << endl<<lib.userList[i].getUsername() << " " << lib.userList[i].getPassword() << " " << lib.userList[i].getStatus();
	}
	fout.close();
}

void User::printAllBook()
{
	ofstream fout;
	fout.open("Book.txt", ios::trunc);
	if (!fout)
	{
		cerr << "Book.txt can't open!" << endl;
		exit(0);
	}
	fout << endl << lib.bookList[0].getID() << " " << lib.bookList[0].getName() << " " << lib.bookList[0].getType() << " " << lib.bookList[0].getAuthor() << " " << lib.bookList[0].getPublisher() << " " << lib.bookList[0].getNumber() << " " << lib.bookList[0].getPrice();
	for (int i = 1; i < lib.bookList.size(); i++)
	{
		fout << endl<<lib.bookList[i].getID() << " " << lib.bookList[i].getName() << " " << lib.bookList[i].getType() << " " << lib.bookList[i].getAuthor() << " " << lib.bookList[i].getPublisher() << " " << lib.bookList[i].getNumber() << " " << lib.bookList[i].getPrice();
	}
	fout.close();
}

void User::printCash()
{
	ofstream fout;
	fout.open("Cash.txt");
	if (!fout)
	{
		cerr << "Cash.txt can't open!" << endl;
		exit(0);
	}
	fout << lib.getIncome() << " "<<lib.getOutcome()<<endl;
	fout.close();
}

void User::listBookAll()
{
	system("cls");
	string choice;
	cout << "This is the book list:" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	for (int i = 0; i < lib.bookList.size(); i++)
		lib.bookList[i].outBook();
	cout << "-------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> choice;
	while (choice != "0")
		cin >> choice;
}

void User::listBookByName()
{
	system("cls");
	string temp, name;
	cout << "Please enter the name you want to find: " << endl;
	cin >> name;
	system("cls");
	cout << "This is the list of all the book that name contains string \"" << name << " \" :" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (int i = 0; i < lib.bookList.size(); i++) // Output each book information match this name
		if (lib.bookList[i].getName().find(name) != string::npos) {
			lib.bookList[i].outBook();
		}
	cout << "-------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
}

void User::changePassword()
{
	system("cls");
	string temp, password;
	cout << "Please enter the new password you want to change: " << endl;
	cin >> password;
	cout << "Please repeat it: " << endl;
	cin >> temp;
	if (temp != password)
	{
		cout << "It doesn't match!! Change password failed..." << endl;
		Sleep(1500);
		return;
	}
	else
	{
		for (int i = 0; i < lib.userList.size(); i++)
		{
			if (lib.userList[i].getUsername() == account)
				lib.userList[i].setPassword(password);
		}
		cout << "Password change successfully !" << endl;
		rec.userLog(account, account, "psw", 0);
		printAllUser();
		Sleep(2000);
	}
}