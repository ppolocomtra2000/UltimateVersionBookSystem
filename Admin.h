#pragma once
#include "Author.h"
#include "Publisher.h"
#include "Staff.h"
class Admin :
	public Author,public Publisher,public Staff
{
public:
	void addUser();
	void delUser();
	void setUser();	//update position
	void Interface(string username);
private:
	void listUser();
};

