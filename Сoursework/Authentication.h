#pragma once
#include "Encryption.h"
#include <string>;
#include <conio.h>;

class Authentication{
public:
    Authentication(){}
    Authentication(string login, string password, string role, int user_balance) : login(login), password(password), role(role), user_balance(user_balance){}

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
    void getBalance() { upd_balance(); cout << "Ваш баланс: " << user_balance << " р." << endl; system("pause"); }
    void add_balance();

private:
    bool checkLuhn(const string& cardNo);
	void writeEndFileAccounts();
	string setLogin();
	string setPassword();
	char* encryption();
    void upload_information(vector<Authentication>& v);
    void upd_balance();
    friend istream& operator>>(istream& stream,Authentication& v) {
        stream >> v.login;
        stream >> v.password;
        stream >> v.role;
        stream >> v.user_balance;
        return stream;
    }
    friend ostream& operator<<(ostream& stream, const Authentication& v) {
        stream << v.login<< " " << v.password<< " " << v.role<< " "<< v.user_balance;
        return stream;
    }
    Authentication& operator=(const Authentication&) = default;
};

