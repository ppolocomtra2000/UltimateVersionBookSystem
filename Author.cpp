#include "Author.h"

extern Library lib;
extern Log rec;
extern string account;

void Author::addBook()
{
	system("cls");
	Book newBook;
	int ID, number;
	string name, type, publisher;
	float price;
	cout << "Please enter book name: ";
	cin >> name;
	for (int i = 0; i < authorList.size(); i++)
	{
		if (authorList[i].getName() == name)
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
	cout << "Publisher: " << endl;
	cin >> publisher;
	cout << "Number of this copies: " << endl;
	cin >> number;
	cout << "Price each copy: " << endl;
	cin >> price;
	newBook.setID(ID);
	newBook.setName(name);
	newBook.setType(type);
	newBook.setAuthor(authorName);
	newBook.setPublisher(publisher);
	newBook.setNumber(number);
	newBook.setPrice(price);
	authorList.push_back(newBook);
	lib.bookList.push_back(newBook);
	cout << "Add book successfully!" << endl;
	Sleep(1000);
	rec.bookLog(account, name, "addAuthor", number);
	rec.cashLog(account, name, "addAuthor", double(price * number));
	printAllBook();
	printCash();
}

void Author::delBook()
{
	system("cls");
	string name;
	int ID, temp;
	cout << "Please enter book name you want to delete: " << endl;
	cin >> name;
	for (int i = 0; i < authorList.size(); i++)
	{
		if (authorList[i].getName() == name)
		{
			cout << "There are " << authorList[i].getNumber() << " copies of this book, how many you want to delete: " << endl;
			cin >> temp;
			if (temp > authorList[i].getNumber())
			{
				cout << "Book number is not that much" << endl;
				Sleep(1000);
			}
			else
			{
				authorList[i].setNumber(authorList[i].getNumber() - temp);
			}
			break;
		}
	}
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (name == lib.bookList[i].getName() && lib.bookList[i].getAuthor() == authorName)
		{
			lib.bookList[i].setNumber(lib.bookList[i].getNumber() - temp);
			cout << "Delete " << temp << " copies of this book successfully!" << endl;
			Sleep(1000);
			rec.bookLog(account, name, "delAuthor", temp);
			printAllBook();
			break;
		}
	}
}

void Author::setBook()
{
	system("cls");
	int choice;
	int ID, number;
	string name, type, publisher;
	double price;
	cout << "Please enter the book name you want to change information: " << endl;
	cin >> name;
	for (int i = 0; i < authorList.size(); i++)
	{
		if (authorList[i].getName() == name)
		{
			cout << "Do you want to change this ID ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new ID: " << endl;
				cin >> ID;
				authorList[i].setID(ID);
			}
			cout << "Do you want to change this type ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new type: " << endl;
				cin >> type;
				authorList[i].setType(type);
			}
			cout << "Do you want to change this publisher ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new publisher: " << endl;
				cin >> publisher;
				authorList[i].setPublisher(publisher);
			}
			cout << "Do you want to change this number of copies ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new number of copies: " << endl;
				cin >> number;
				authorList[i].setNumber(number);
			}
			cout << "Do you want to change this price ( 1 for YES, 0 for NO) ?" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Please enter the new price: " << endl;
				cin >> price;
				authorList[i].setPrice(price);
			}
			break;
		}
	}
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (lib.bookList[i].getName() == name && lib.bookList[i].getAuthor() == authorName)
		{
			lib.bookList[i].setID(ID);
			lib.bookList[i].setType(type);
			lib.bookList[i].setAuthor(authorName);
			lib.bookList[i].setPublisher(publisher);
			lib.bookList[i].setNumber(number);
			lib.bookList[i].setPrice(price);
			cout << "Change book's information successfully!" << endl;
			Sleep(1000);
			rec.bookLog(account, name, "setAuthor", 0);
			printAllBook();
			return;
		}
	}
	cout << "Not found this book!" << endl;
	Sleep(1000);
}

void Author::viewProfit()
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

void Author::Interface(string username)
{
	int choice;
	//filterBookByAuthor();
	while (1)
	{
		system("cls");
		cout << "Welcome " << username << ". You are author" << endl;
		cout << "Please choose what you want to do by input number " << endl;
		while (1)
		{
			cout << "1.Add new book" << endl;
			cout << "2. Delete book" << endl;
			cout << "3. Change book's information" << endl;
			cout << "4. List book ( all )" << endl;
			cout << "5. List book ( by authorName )" << endl;
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
			outAuthorList();
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

void Author::filterBookByAuthor()
{
	cout << "Enter author's name: " << endl;
	cin >> authorName;
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (lib.bookList[i].getAuthor() == authorName)
			authorList.push_back(lib.bookList[i]);
	}
}

void Author::outAuthorList()
{
	string choice;
	filterBookByAuthor();
	cout << "List book of " <<authorName<<" :"<< endl;
	cout << "----------------------------" << endl;
	for (int i = 0; i < authorList.size(); i++)
		authorList[i].outBook();
	cout << "----------------------------" << endl;
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> choice;
	while (choice != "0")
		cin >> choice;
}