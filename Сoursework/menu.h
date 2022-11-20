#pragma once
#include <iostream>
#include"Validators.h"


using namespace std;
namespace menu {
    void auth_menu();
    void first_admin_menu();
    void user_menu();
    void admin_menu();
    void sor_fil_menu();
}

void menu::auth_menu() {
    center(30, 12);
    color(177);
    cout << "\t\tМеню:" << endl;
    center(25, 13);
    color(177);
    cout << "\t(1) ~ Войти в аккаунт"<< endl;
    center(25, 14);
    color(177);
    cout << "\t(2) ~ Регистрация нового пользователя" << endl;
    center(25, 15);
    color(177);
    cout << "\t(3) ~ Выход" << endl;
    center(25, 16);
    color(177);
    cout << "Ваш Выбор: ";
}

void menu::first_admin_menu() {
    center(30, 10);
    cout << "\t\tВыбор меню(Только для админа):" << endl;
    center(30, 11);
    cout << "\t(1) ~ Войти как Админ" << endl;
    center(30, 12);
    cout << "\t(2) ~ Войти как Пользователь" << endl;
    center(30, 13);
    cout << "\t(3) ~ Выход" << endl;
    center(30, 14);
    cout << "Ваш Выбор: ";
}
void menu::user_menu() {
    center(30, 10);
    cout << "\t\tМеню:" << endl;
    center(30, 11);
    cout << "\t(1) ~ Просмотреть все игры" << endl;
    center(30, 12);
    cout << "\t(2) ~ Сделать ставку" << endl;
    center(30, 13);
    cout << "\t(3) ~ Ваш баланс" << endl;
    center(30, 14);
    cout << "\t(4) ~ Пополнить баланс" << endl;
    center(30, 15);
    cout << "\t(5) ~ Сыграть в рултеку" << endl;
    center(30, 16);
    cout << "\t(6) ~ Выход" << endl;
    center(30, 17);
    cout << "Ваш выбор: ";
}
void menu::admin_menu() {
    cout << "\t\tМеню:" << endl;
    cout << "\t(1) ~ Добавить игру" << endl;
    cout << "\t(2) ~ Удалить игру" << endl;
    cout << "\t(3) ~ Редактировать игру" << endl;
    cout << "\t(4) ~ Редактировать юзеров" << endl;
    cout << "\t(5) ~ Просмотреть все игры" << endl;
    cout << "\t(6) ~ Назад" << endl;
    cout << "Ваш выбор: ";
}
void menu::sor_fil_menu() {
    cout << endl;
    cout << "\t\tМеню:" << endl;
    cout << "\t(1) ~ Выбрать меню сортировки" << endl;
    cout << "\t(2) ~ Выбрать меню фильтрации" << endl;
    cout << "Ваш выбор: ";
}


