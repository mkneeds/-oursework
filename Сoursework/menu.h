#pragma once
#include <iostream>

using namespace std;

namespace menu {
    void auth_menu();
    void first_admin_menu();
    void user_menu();
}

void menu::auth_menu() {
    cout << "\t\t���� ����� � �������:" << endl;
    cout << "\t(1) ~ �����������" << endl;
    cout << "\t(2) ~ �����������" << endl;
    cout << "\t(3) ~ �����" << endl;
    cout << "��� �����: ";
}

void menu::first_admin_menu() {
    cout << "\t\t����� ����:" << endl;
    cout << "\t(1) ~ ������������ ���� ������" << endl;
    cout << "\t(2) ~ ������������ ���� ������������" << endl;
    cout << "\t(3) ~ �����" << endl;
    cout << "��� �����: ";
}
void menu::user_menu() {
    cout << "\t\tV���:" << endl;
    cout << "\t(1) ~ ���������� ����" << endl;
    cout << "\t(2) ~ ������� ������" << endl;
    cout << "\t(3) ~ ��������� �������" << endl;
    cout << "\t(4) ~ �����" << endl;
    cout << "��� �����: ";
}




