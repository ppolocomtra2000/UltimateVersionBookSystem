#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>
#include "Log.h"
class User
{
private:
	int status;// status: 3 for customer,2 for author,1 for publisher,0 for not exist,5 for admin
	string username;
	string password;
public:
	void listBookAll();
	void listBookByName();
	//print all data to file
	void printAllUser();
	void printAllBook();
	void printCash();
	//get information of User

	string getUsername() { return this->username; };
	string getPassword() { return this->password; };
	int getStatus() { return this->status; };

	//set information of User

	void setUsername(string name) { this->username = name; };
	void setPassword(string pass) { this->password = pass; };
	void setStatus(int num) { this->status = num; };

	//change Password
	void changePassword();

	//interface
	virtual void Interface(string username) {};
};

