#pragma once
#include "Validators.h"
#include "Encryption.h"

#include <string>;
#include <conio.h>;
#include <fstream>
#include <Windows.h>
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
    float user_balance = 0;
public:
    int getMoney() { return user_balance; }
    void change_user();
	int auth();
	void regestration();
    int8_t getAccessInf() { return access_inf; }
    void getBalance() { upd_balance(); cout << "Ваш баланс: " << user_balance << " р." << endl; system("pause"); }
    void add_balance();
    void upd_balance();
    void upd_Balance(float money);
    void plus(float money);
private:
    bool checkLuhn(const string& cardNo);
	void writeEndFileAccounts();
	string setLogin();
	string setPassword();
	char* encryption();
    void upload_information(vector<Authentication>& v);
   
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

