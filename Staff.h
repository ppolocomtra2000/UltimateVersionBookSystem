#pragma once
#include "User.h"
#include "Library.h"
class Staff :
	public User
{
protected:
	void viewProfit();
public:
	void addBook();
	void delBook();
	void setBook();
	void Interface(string username);
};

