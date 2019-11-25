#pragma once
#include <string>

using namespace std;

class Book
{
private:
	int ID;
	string name;
	string type;
	string author;
	string publisher;
	int number;
	double price;
public:
	//set 
	void setName(string name) { this->name = name; };
	void setID(int ID) { this->ID = ID; };
	void setAuthor(string author) { this->author = author; };
	void setPublisher(string publisher) { this->publisher = publisher; };
	void setNumber(int number) { this->number = number; };
	void setType(string type) { this->type = type; };
	void setPrice(double price) { this->price = price; };
	//get
	string getName() { return this->name; };
	int getID() { return this->ID; };
	string getAuthor() { return this->author; };
	string getPublisher() { return this->publisher; };
	int getNumber() { return this->number; };
	string getType() { return this->type; };
	double getPrice() { return this->price; };
	//netPrice
	double netPrice(int num) {
		return ((double)num * price);
	};
	//output
	void outBook();
};

