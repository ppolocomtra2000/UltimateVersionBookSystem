#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Log
{
public:
	void userLog(string loginname, string username, string operation, int status);
	void bookLog(string loginname, string bookName, string operation, int number);
	void cashLog(string loginname, string bookName, string operation, double money);
};

