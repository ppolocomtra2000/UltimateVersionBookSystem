#pragma once
#include "Library.h"
#include "Log.h"
#include "Book.h"
#include "User.h"
#include "Staff.h"
#include "Admin.h"
#include "Customer.h"
#include "Password.h"

Log rec;
Library lib;
Password pass;
string account;

int login(string username, string password);
void loadData();
void welcome();