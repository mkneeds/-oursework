#pragma once
#include "Encryption.h"
#include <string>;
#include <conio.h>;

class Authentication{

private:
	Encryption enc;
	string login;
	string password;
	string role;
public:
	int8_t access_reg = 1; // 0 - NO 1 - YES
	int8_t access_inf = 0;// change and admin mode
	int8_t access_log = 0;// acc in auth
	string file = "Auth.txt";
public:
	void auth();
	void regestration();
private:
	void writeEndFileAccounts();
	int checkFirstAccounts();
	string setLogin();
	string setPassword();
	char* encryption();
	
};

