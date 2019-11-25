#include "Log.h"
#include "Library.h"
#include <Windows.h>

extern Library lib;

void Log::userLog(string loginname, string username, string operation, int status)
{
	ofstream fout;
	fout.open("UserLog.txt", ios::app);
	if (!fout)
	{
		cerr << "UserLog.txt can't open!" << endl;
		exit(0);
	}
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << "-" << sys.wHour << "-" << sys.wMinute << "-" << sys.wSecond << " ]";
	if (operation == "add")
		fout << "Admin(" << loginname << ") add a new user(" << username << ")" << endl;
	else if (operation=="del")
		fout << "Admin(" << loginname << ") delete a user(" << username << ")" << endl;
	else if (operation=="set")
		fout << " Admin(" << loginname << ") set user(" << username << ")'s status to (" << status << ") " << endl;
	else if (operation=="psw")
		fout << " User(" << loginname << ") change his/her password " << endl;
	fout.close();
}

void Log::bookLog(string loginname, string bookName, string operation, int number) { // Add new information to BookLog.txt
	ofstream fout;
	fout.open("BookLog.txt", ios::app); // Open and append to BookLog.txt
	if (!fout) { // If can't open
		cerr << "BookLog.txt can't open" << endl;
		abort(); // Exit
	}
	SYSTEMTIME sys;
	GetLocalTime(&sys); // Get system time
	fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]"; // Output system tiime
	if (operation == "buy")
		fout << " Customer(" << loginname << ") buy books(Name:" << bookName << ") with " << number << " copy(s)" << endl;
	else if (operation == "ref")
		fout << " Customer(" << loginname << ") refund books(Name:" << bookName << ") with " << number << " copy(s)" << endl;
	else if (operation == "addAuthor")
		fout << " Author(" << loginname << ") add new books(Name:" << bookName << ") with " << number << " copy(s)" << endl;
	else if (operation == "delAuthor")
		fout << " Author(" << loginname << ") delete books(Name:" << bookName << ") with " << number << " copy(s)" << endl;
	else if (operation == "addPublisher")
		fout << " Publisher(" << loginname << ") add new books(Name:" << bookName << ") with " << number << " copy(s)" << endl;
	else if (operation == "delPublisher")
		fout << " Publisher(" << loginname << ") delete books(Name:" << bookName << ") with " << number << " copy(s)" << endl;
	else if (operation == "setAuthor")
		fout << " Author(" << loginname << ") change book(Name:" << bookName << ")'s information " << endl;
	else if (operation == "setPublisher")
		fout << " Publisher(" << loginname << ") change book(Name:" << bookName << ")'s information " << endl;
	else if (operation == "add")
		fout << " Admin(" << loginname << ") add new books(Name:" << bookName << ") with " << number << " copy(s)" << endl;
	else if (operation == "del")
		fout << " Admin(" << loginname << ") delete books(Name:" << bookName << ") with " << number << " copy(s)" << endl;
	else if(operation == "set")
		fout << " Admin(" << loginname << ") change book(Name:" << bookName << ")'s information " << endl;
	fout.close(); // Close BookLog.txt
}

void Log::cashLog(string loginname, string bookName, string operation, double money) { // Add new information to CashLog.txt
	ofstream fout;
	fout.open("CashLog.txt", ios::app); // Open and append to BookLog.txt
	if (!fout) { // If can't open
		cerr << "CashLog.txt can't open" << endl;
		abort(); // Exit
	}
	SYSTEMTIME sys;
	GetLocalTime(&sys); // Get system time
	fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]"; // Output system tiime
	if (operation == "add") {
		fout << " Admin(" << loginname << ") add new books(ID:" << bookName << ") ---------- Outcome: " << money << endl;
		lib.setOutcome(money + lib.getOutcome());
	}
	else if (operation == "addAuthor") {
		fout << " Author(" << loginname << ") add new books(ID:" << bookName << ") ---------- Outcome: " << money << endl;
		lib.setOutcome(money + lib.getOutcome());
	}
	else if (operation == "addPublisher") {
		fout << " Publisher(" << loginname << ") add new books(ID:" << bookName << ") ---------- Outcome: " << money << endl;
		lib.setOutcome(money + lib.getOutcome());
	}
	else if (operation == "buy") {
		fout << " Customer(" << loginname << ") buy books(Name:" << bookName << ") ---------- Income: " << money << endl;
		lib.setIncome(money + lib.getIncome());
	}
	else if (operation == "ref") {
		fout << " Customer(" << loginname << ") refund books(Name:" << bookName << ") ---------- Outcome: " << money << endl;
		lib.setOutcome(money + lib.getOutcome());
	}
	fout.close(); // Close CashLog.txt
}
