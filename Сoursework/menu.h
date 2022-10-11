#pragma once
#include <iostream>

using namespace std;

namespace menu {
    void auth_menu();
    void first_admin_menu();
    void user_menu();
}

void menu::auth_menu() {
    cout << "\t\tМеню входа в систему:" << endl;
    cout << "\t(1) ~ Авторизация" << endl;
    cout << "\t(2) ~ Регистрация" << endl;
    cout << "\t(3) ~ Выход" << endl;
    cout << "Ваш выбор: ";
}

void menu::first_admin_menu() {
    cout << "\t\tВыбор меню:" << endl;
    cout << "\t(1) ~ Использовать меню админа" << endl;
    cout << "\t(2) ~ Использовать меню пользователя" << endl;
    cout << "\t(3) ~ Выход" << endl;
    cout << "Ваш выбор: ";
}
void menu::user_menu() {
    cout << "\t\tVеню:" << endl;
    cout << "\t(1) ~ Посмотреть игры" << endl;
    cout << "\t(2) ~ Сделать ставку" << endl;
    cout << "\t(3) ~ Пополнить баланск" << endl;
    cout << "\t(4) ~ Выход" << endl;
    cout << "Ваш выбор: ";
}




