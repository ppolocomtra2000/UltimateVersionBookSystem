#include "Publisher.h"

extern Library lib;
extern Log rec;
extern string account;

void Publisher::addBook()
{
	system("cls");
	Book newBook;
	int ID, number;
	string name, type, author;
	float price;
	cout << "Please enter book name: ";
	cin >> name;
	for (int i = 0; i < publisherList.size(); i++)
	{
		if (publisherList[i].getName() == name)
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
	newBook.setPublisher(publisherName);
	newBook.setNumber(number);
	newBook.setPrice(price);
	publisherList.push_back(newBook);
	lib.bookList.push_back(newBook);
	cout << "Add book successfully!" << endl;
	Sleep(1000);
	rec.bookLog(account, name, "addPublisher", number);
	rec.cashLog(account, name, "addPublisher", double(price * number));
	printAllBook();
	printCash();
}

void Publisher::delBook()
{
	system("cls");
	string name;
	int ID, temp;
	cout << "Please enter book name you want to delete: " << endl;
	cin >> name;
	for (int i = 0; i < publisherList.size(); i++)
	{
		if (publisherList[i].getName() == name)
		{
			cout << "There are " << publisherList[i].getNumber() << " copies of this book, how many you want to delete: " << endl;
			cin >> temp;
			if (temp > publisherList[i].getNumber())
			{
				cout << "Book number is not that much" << endl;
				Sleep(1000);
			}
			else
			{
				publisherList[i].setNumber(publisherList[i].getNumber() - temp);
			}
			break;
		}
	}
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (name == lib.bookList[i].getName() && lib.bookList[i].getPublisher() == publisherName)
		{
			lib.bookList[i].setNumber(lib.bookList[i].getNumber() - temp);
			cout << "Delete " << temp << " copies of this book successfully!" << endl;
			Sleep(1000);
			rec.bookLog(account, name, "delPublisher", temp);
			printAllBook();
		}
	}
}

void Publisher::setBook()
{
	system("cls");
	int choice;
	int ID, number;
	string name, type, author;
	double price;
	cout << "Please enter the book name you want to change information: " << endl;
	cin >> name;
	for (int i = 0; i < publisherList.size(); i++)
	{
		if (publisherList[i].getName() == name)
		{
			cout << "Do you want to change this ID ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new ID: " << endl;
				cin >> ID;
				publisherList[i].setID(ID);
			}
			cout << "Do you want to change this type ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new type: " << endl;
				cin >> type;
				publisherList[i].setType(type);
			}
			cout << "Do you want to change this author ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new author: " << endl;
				cin >> author;
				publisherList[i].setAuthor(author);
			}
			cout << "Do you want to change this number of copies ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new number of copies: " << endl;
				cin >> number;
				publisherList[i].setNumber(number);
			}
			cout << "Do you want to change this price ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new price: " << endl;
				cin >> price;
				publisherList[i].setPrice(price);
			}
			break;
		}
	}
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (lib.bookList[i].getName() == name && lib.bookList[i].getPublisher() == publisherName)
		{
			lib.bookList[i].setID(ID);
			lib.bookList[i].setType(type);
			lib.bookList[i].setAuthor(author);
			lib.bookList[i].setPublisher(publisherName);
			lib.bookList[i].setNumber(number);
			lib.bookList[i].setPrice(price);
			cout << "Change book's information successfully!" << endl;
			Sleep(1000);
			rec.bookLog(account, name, "setPublisher", 0);
			printAllBook();
			return;
		}
	}
}

void Publisher::viewProfit()
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

void Publisher::Interface(string username)
{
	int choice;
	while (1)
	{
		system("cls");
		cout << "Welcome " << username << ". You are publisher" << endl;
		cout << "Please choose what you want to do by input number " << endl;
		while (1)
		{
			cout << "1.Add new book" << endl;
			cout << "2. Delete book" << endl;
			cout << "3. Change book's information" << endl;
			cout << "4. List book ( all )" << endl;
			cout << "5. List book ( by publisher name )" << endl;
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
			outPublisherList();
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

void Publisher::filterBookByPublisher()
{
	cout << "Enter publisher's name: " << endl;
	cin >> publisherName;
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (lib.bookList[i].getPublisher() == publisherName)
			publisherList.push_back(lib.bookList[i]);
	}
}

void Publisher::outPublisherList()
{
	string choice;
	filterBookByPublisher();
	cout << "List book of " << publisherName << " :" << endl;
	cout << "----------------------------" << endl;
	for (int i = 0; i < publisherList.size(); i++)
		publisherList[i].outBook();
	cout << "----------------------------" << endl;
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> choice;
	while (choice != "0")
		cin >> choice;
}