#pragma once
#include "User.h"
#include "Library.h"
class Publisher :
	public User
{
protected:
	string publisherName;
	vector <Book> publisherList;
	void filterBookByPublisher();
	void viewProfit();
public:
	void addBook();
	void delBook();
	void setBook();
	void Interface(string username);
	void outPublisherList();
};

