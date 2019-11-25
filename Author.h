#pragma once
#include "User.h"
#include "Library.h"
class Author :
	public User
{
protected:
	string authorName;
	vector <Book> authorList;
	void filterBookByAuthor();
	void viewProfit();
public:
	void addBook();
	void delBook();
	void setBook();
	void Interface(string username);
	void outAuthorList();
};

