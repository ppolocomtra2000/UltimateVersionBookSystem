#include "Library.h"

void Library::loadUser()
{
	User oldUser;
	string username,pass,line;
	int status;
	ifstream fin("User.txt");
	if (!fin)
	{
		cerr << "User.txt can't open!" << endl;
		exit(0);
	}
	//read first line
	fin >> username >> pass >> status;
	oldUser.setUsername(username);
	oldUser.setPassword(pass);
	oldUser.setStatus(status);
	userList.push_back(oldUser);
	//the whole line
	while (getline(fin,line))
	{
		fin >> username >> pass >> status;
		oldUser.setUsername(username);
		oldUser.setPassword(pass);
		oldUser.setStatus(status);
		userList.push_back(oldUser);
	}
	fin.close();
}

void Library::loadBook()
{
	Book oldBook;
	string line,name,author,type,publisher;
	int ID, number;
	double price;
	ifstream fin("Book.txt");
	if (!fin)
	{
		cerr << "Book.txt can't open" << endl;
		exit(0);
	}
	//read first line in file book.txt
	fin >> ID >> name >> type >> author >> publisher >> number >> price;
	oldBook.setID(ID);
	oldBook.setName(name);
	oldBook.setType(type);
	oldBook.setAuthor(author);
	oldBook.setPublisher(publisher);
	oldBook.setNumber(number);
	oldBook.setPrice(price);
	bookList.push_back(oldBook);
	//read the others line 
	while (getline(fin, line))
	{
		fin >> ID >> name >> type >> author >> publisher>>number >> price;
		oldBook.setID(ID);
		oldBook.setName(name);
		oldBook.setType(type);
		oldBook.setAuthor(author);
		oldBook.setPublisher(publisher);
		oldBook.setNumber(number);
		oldBook.setPrice(price);
		bookList.push_back(oldBook);
	}
	fin.close();
}

void Library::loadCash()
{
	ifstream fin("Cash.txt");
	if (!fin)
	{
		cerr << "Cash.txt can't open!" << endl;
		exit(0);
	}
	fin >> income >> outcome;
	fin.close();
}