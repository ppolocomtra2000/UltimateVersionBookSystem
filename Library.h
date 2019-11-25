#pragma once
#include <vector>
#include "Book.h"
#include "User.h"

class Library // = List book 
{
private:
	double income, outcome;
public:
	//load data
	void loadUser();
	void loadBook();
	void loadCash();
	//set
	void setIncome(double income) { this->income = income; };
	void setOutcome(double outcome) { this->outcome = outcome; };
	//get
	double getIncome() { return this->income; };
	double getOutcome() { return this->outcome; };
	//store
	vector <Book> bookList;
	vector <User> userList;
};

