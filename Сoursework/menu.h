#pragma once
#include <iostream>

using namespace std;

namespace menu {
    void auth_menu();
    void first_admin_menu();
    void user_menu();
    void admin_menu();
    void sor_fil_menu();
}

void menu::auth_menu() {
    cout << "\t\tМеню:" << endl;
    cout << "\t(1) ~ Войти в аккаунт"<< endl;
    cout << "\t(2) ~ Регистрация нового пользователя" << endl;
    cout << "\t(3) ~ Выход" << endl;
    cout << "Ваш Выбор: ";
}

void menu::first_admin_menu() {
    cout << "\t\tВыбор меню(Только для админа):" << endl;
    cout << "\t(1) ~ Войти как Админ" << endl;
    cout << "\t(2) ~ Войти как Пользователь" << endl;
    cout << "\t(3) ~ Выход" << endl;
    cout << "Ваш Выбор: ";
}
void menu::user_menu() {
    cout << "\t\tМеню:" << endl;
    cout << "\t(1) ~ Просмотреть все игры" << endl;
    cout << "\t(2) ~ Сделать ставку" << endl;
    cout << "\t(3) ~ Пополнить баланс" << endl;
    cout << "\t(4) ~ Выход" << endl;
    cout << "Ваш выбор: ";
}
void menu::admin_menu() {
    cout << "\t\tМеню:" << endl;
    cout << "\t(1) ~ Добавить игру" << endl;
    cout << "Ваш выбор: ";
}
void menu::sor_fil_menu() {
    cout << endl;
    cout << "\t\tМеню:" << endl;
    cout << "\t(1) ~ Выбрать меню сортировки" << endl;
    cout << "\t(2) ~ Выбрать меню фильтрации" << endl;
    cout << "Ваш выбор: ";
}


