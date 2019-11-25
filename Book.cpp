#include "Book.h"
#include <iostream>



void Book::outBook()
{
	cout << "-----------------" << endl;
	cout << "ID: " << Book::getID() << endl;
	cout << "Name: " << getName() << endl;
	cout << "Type: " << getType() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Publisher: " << getPublisher() << endl;
	cout << "Number: " << getNumber() << endl;
	cout << "Price: " << getPrice() << endl;
	cout << "-------------------" << endl;
}