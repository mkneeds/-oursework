
#include "Validators.h"
#include "Authentication.h"
#include <Windows.h>
#include "SmartPointer.cpp"
#include "menu.h"
#include "Game.h"

using namespace menu;

void main(int argc, TCHAR* argv[])
{
    HWND console = GetConsoleWindow();
    HMENU menu = GetSystemMenu(console, FALSE);
    DeleteMenu(menu, SC_CLOSE, MF_BYCOMMAND);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    SmartPointer<Game> game = new Game();
	SmartPointer <Authentication> a = new Authentication();
    bool flag = TRUE;
    while (flag) {
        auth_menu();
        switch (checkInterval(1, 3)) {
        case 1: flag = a->auth(); system("cls"); break;
        case 2: a->regestration(); system("cls"); break;
        case 3: exit(0);
        }
    }
    int8_t user = 0;
    flag = TRUE;
    if (a->getAccessInf() == 1) {
        while (flag) {
            first_admin_menu();
            switch (checkInterval(1, 3)) {
            case 1: flag = FALSE; break;
            case 2: user = 1; flag = FALSE; break;
            case 3: exit(0);
            }
        }
    }
    if(a->getAccessInf() == 0 || user == 1 ){
        while (1) {
            system("cls");
            user_menu();
            switch (checkInterval(1, 4)) {
            case 1: system("cls"); game->print_game(); sor_fil_menu(); {
                switch (checkInterval(1, 2)) {
                case 1: system("cls"); game->sort_game(); system("pause"); break;
                case 2: system("cls"); game->filt_game(); system("pause"); break;
                }
            }; break;
            case 2: break;
            case 3: break;
            case 4: exit(0);
            }
        }
    }
    if (user == 0) {
        while (1) {
            system("cls");
            menu::admin_menu();
            switch (checkInterval(1, 4)) {
            case 1: system("cls"); game->add_game(); break;
            case 2: system("cls"); game->delete_game(); system("pause"); break;
            case 3: system("cls"); game->edit_game(); system("pause"); break;
            }
        }
    }

}

