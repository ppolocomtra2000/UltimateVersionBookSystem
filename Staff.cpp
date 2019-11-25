#include "Staff.h"

extern Library lib;
extern Log rec;
extern string account;

void Staff::addBook()
{
	system("cls");
	Book newBook;
	int ID, number;
	string name, type, author;
	float price;
	cout << "Please enter book name: ";
	cin >> name;
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (lib.bookList[i].getName() == name)
		{
			cout << "This book already exist!" << endl;
			Sleep(1000);
			return;
		}
	}
	cout << "ID: " << endl;
	cin >> ID;
	cout << "Type: " << endl;
	cin >> type;
	cout << "Author: " << endl;
	cin >> author;
	cout << "Number of this copies: " << endl;
	cin >> number;
	cout << "Price each copy: " << endl;
	cin >> price;
	newBook.setID(ID);
	newBook.setName(name);
	newBook.setType(type);
	newBook.setAuthor(author);
	newBook.setNumber(number);
	newBook.setPrice(price);
	lib.bookList.push_back(newBook);
	cout << "Add book successfully!" << endl;
	Sleep(1000);
	rec.bookLog(account, name, "add", number);
	rec.cashLog(account, name, "add", double(price * number));
	printAllBook();
	printCash();
}

void Staff::delBook()
{
	system("cls");
	string name;
	int ID,temp;
	cout << "Please enter book name you want to delete: " << endl;
	cin >> name;
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (lib.bookList[i].getName() == name)
		{
			cout << "There are " << lib.bookList[i].getNumber() << " copies of this book, how many you want to delete: " << endl;
			cin >> temp;
			if (temp > lib.bookList[i].getNumber())
			{
				cout << "Book number is not that much" << endl;
				Sleep(1000);
			}
			else
			{
				lib.bookList[i].setNumber(lib.bookList[i].getNumber() - temp);
				cout << "Delete " << temp << " copies of this book successfully!" << endl;
				Sleep(1000);
				rec.bookLog(account, name, "del", temp);
				printAllBook();
			}
		}
	}
	cout << "Not found this book!" << endl;
	Sleep(1000);
}

void Staff::setBook()
{
	system("cls");
	int choice;
	int ID, number;
	string name, type, author;
	double price;
	cout << "Please enter the book name you want to change information: " << endl;
	cin >> name;
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (lib.bookList[i].getName() == name)
		{
			cout << "Do you want to change this ID ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new ID: " << endl;
				cin >> ID;
				lib.bookList[i].setID(ID);
			}
			cout << "Do you want to change this type ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new type: " << endl;
				cin >> type;
				lib.bookList[i].setType(type);
			}
			cout << "Do you want to change this author ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new author: " << endl;
				cin >> ID;
				lib.bookList[i].setAuthor(author);
			}
			cout << "Do you want to change this number of copies ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new number of copies: " << endl;
				cin >> number;
				lib.bookList[i].setNumber(number);
			}
			cout << "Do you want to change this price ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new price: " << endl;
				cin >> price;
				lib.bookList[i].setPrice(price);
			}
			cout << "Change book's information successfully!" << endl;
			Sleep(1000);
			rec.bookLog(account, name, "set", 0);
			printAllBook();
			return;
		}
	}
	cout << "Not found this book!" << endl;
	Sleep(1000);
}

void Staff::viewProfit()
{
	system("cls");
	string temp;
	cout << "Total income: " << lib.getIncome() << endl;
	cout << "Total outcome: " << lib.getOutcome() << endl;
	cout << "Total net profit: " << lib.getIncome() - lib.getOutcome() << endl;
	cout << "Enter 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
	return;
}

void Staff::Interface(string username)
{
	int choice;
	while (1)
	{
		system("cls");
		cout << "Welcome " << username << ". You are staff" << endl;
		cout << "Please choose what you want to do by input number " << endl;
		while (1)
		{
			cout << "1.Add new book" << endl;
			cout << "2. Delete book" << endl;
			cout << "3. Change book's information" << endl;
			cout << "4. List book ( all )" << endl;
			cout << "5. List book ( by name )" << endl;
			cout << "6. Lookup net profit" << endl;
			cout << "7. Change my password" << endl;
			cout << "0. Exit" << endl;
			cin >> choice;
			if (choice < 0 || choice > 7)
			{
				cout << "Wrong! Input again" << endl;
			}
			else break;
		}
		switch (choice)
		{
		case 1:
			addBook();
			break;
		case 2:
			delBook();
			break;
		case 3:
			setBook();
			break;
		case 4:
			listBookAll();
			break;
		case 5:
			listBookByName();
			break;
		case 6:
			viewProfit();
			break;
		case 7:
			changePassword();
			break;
		case 0:
			exit(0);
		}
	}
}