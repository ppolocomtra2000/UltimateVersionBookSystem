#include "Customer.h"

extern Log rec;
extern Library lib;
extern string account;

int numIn;
int numOut;

void Customer::buyBook()
{
	system("cls");
	int k = 0;
	string name;
	cout << "Please input book name you want to buy: ";
	cin >> name;
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (lib.bookList[i].getName() == name)
		{
			cout << "There are " << lib.bookList[i].getNumber() << " copies of this book, how many would you want to buy?" << endl;
			cin >> numIn;
			if (numIn > lib.bookList[i].getNumber())
			{
				cout << "Book number is not that much!" << endl;
				Sleep(1000);
			}
			else
			{
				lib.bookList[i].setNumber(lib.bookList[i].getNumber() - numIn);
				cart.push_back(lib.bookList[i]);
				cout << "Buy " << numIn << " copies of that book successfully!" << endl;
				Sleep(1000);
				rec.bookLog(account, name,"buy", numIn);
				printAllBook();
				printCash();
			}
		}
	}
	for (int i = 0; i < cart.size(); i++)
	{
		if (cart[i].getName() == name)
			cart[i].setNumber(numIn);
	}
}

void Customer::refund()
{
	system("cls");
	string name;
	cout << "Please input book name you want to refund" << endl;
	cin >> name;
	for (int i = 0; i < lib.bookList.size(); i++)
	{
		if (lib.bookList[i].getName() == name)
		{
			cout << "How many copies of this book do you want to refund?" << endl;
			cin >> numOut;
			lib.bookList[i].setNumber(lib.bookList[i].getNumber() + numOut);
			cout << "Refund " << numOut << " copies of that books, successfully!" << endl;
			Sleep(1000);
			rec.bookLog(account, name, "ref", numOut);
			rec.cashLog(account, name, "ref", lib.bookList[i].netPrice(numOut));
			printAllBook();
			printCash();
		}
	}
	for (int i = 0; i < cart.size(); i++)
	{
		if (cart[i].getName() == name)
			cart[i].setNumber(cart[i].getNumber() - numOut);
	}
}

void Customer::Interface(string username)
{
	int choice;
	while (1)
	{
		cout << "Welcome " << username << ". You are customer" << endl;
		cout << "Please choose what you want to do" << endl;
		while (1)
		{
			cout << "1. Buy Book" << endl;
			cout << "2. Refund" << endl;
			cout << "3. List book (All)" << endl;
			cout << "4. List book (By name)" << endl;
			cout << "5. Change my password" << endl;
			cout << "6. Get my invoice ( online )" << endl;
			cout << "7. Get my invoice ( offline )" << endl;
			cout << "0. Exit" << endl;
			cin >> choice;
			if (choice < 0 || choice >7)
			{
				cout << "Again?" << endl;
			}
			else break;
		}
		switch (choice)
		{
		case 1:
			buyBook();
			break;
		case 2:
			refund();
			break;
		case 3:
			listBookAll();
			break;
		case 4:
			listBookByName();
			break;
		case 5:
			changePassword();
			break;
		case 6:
			printInvoice();
			break;
		case 7:
			printInvoiceToFile();
			break;
		case 0:
			exit(0);
		}
	}
}

void Customer::printInvoice()
{
	cout << "Your invoice:" << endl;
	cout << "--------------------------" << endl;
	for (int i = 0; i < cart.size(); i++)
	{
		cart[i].outBook();
		cout << "Total of this book: " << cart[i].netPrice(cart[i].getNumber())<<endl;
		total += cart[i].netPrice(cart[i].getNumber());
	}
	cout << "==========================" << endl;
	cout << "Total you must pay: " << total << endl;
	cout << "==========================" << endl;
}

void Customer::printInvoiceToFile()
{
	ofstream fout;
	fout.open("invoice.txt", ios::trunc);
	if (!fout)
	{
		cerr << "Invoice.txt can't open!" << endl;
		return;
	}
	fout << "============== YOUR INVOICE =================" << endl;
	for (int i = 0; i < cart.size(); i++)
	{
		fout << "------------------" << endl;
		fout << "ID:" <<cart[i].getID() << endl;
		fout << "Name:" << cart[i].getName() << endl;
		fout << "Type:" << cart[i].getType() << endl;
		fout << "Author:" << cart[i].getAuthor() << endl;
		fout << "Publisher:" << cart[i].getPublisher() << endl;
		fout << "Number of copies:" << cart[i].getNumber() << endl;
		fout << "Price each copies:" << cart[i].getPrice() << endl;
		fout << "--------------------" << endl;
		fout << "Total of this book: " << cart[i].netPrice(cart[i].getNumber()) << endl;
		totalForFile += cart[i].netPrice(cart[i].getNumber());
	}
	fout << "==========================" << endl;
	fout << "Total you must pay: " << totalForFile << endl;
	fout << "==========================" << endl;
	cout << "Done..." << endl;
	fout.close();
}
