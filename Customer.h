#pragma once
#include "User.h"
#include "Library.h"

class Customer: public User
{
private:
	double total;
	double totalForFile;
	vector<Book> cart;
public:
	void setTotal(double total) { this->total = total; };
	double getTotal() { return this->total; };
	void buyBook();
	void refund();
	void Interface(string username);
	void printInvoice();
	void printInvoiceToFile();
};

