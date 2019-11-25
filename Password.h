#pragma once
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

class Password
{
private:
	string psw;
	int length;
public:
	Password() {
		this->psw = "";
		this->length = 0;
	};
	void inputPassword();
	string getPassword() { return this->psw; };
	~Password() {};
	void setPassword(string pass) { this->psw = pass; };
};

