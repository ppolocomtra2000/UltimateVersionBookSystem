#include "Password.h"

void Password::inputPassword()
{
	cin.ignore();
	string pass;
	cout << "Password: ";
	getline(cin, pass);
	setPassword(pass);
}