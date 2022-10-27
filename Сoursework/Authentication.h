#pragma once
#include "Encryption.h"
#include <string>;
#include <conio.h>;

class Authentication{

private:
	Encryption enc;
	string login;
	string password;
	string role = "User";
    int8_t account_point = 0;
	int8_t access_reg = 1; // 0 - NO 1 - YES
	int8_t access_inf = 0;// change and admin mode
	int8_t access_log = 0;// acc in auth
	string file = "Auth.txt";
    int user_balance = 0;
public:
	int auth();
	void regestration();
    int8_t getAccessInf() { return access_inf; }
private:
	void writeEndFileAccounts();
	string setLogin();
	string setPassword();
	char* encryption();
	
};

