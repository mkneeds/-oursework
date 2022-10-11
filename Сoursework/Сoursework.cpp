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
        case 1: flag = a->auth(); break;
        case 2: a->regestration(); break;
        case 3: exit(0);
        }
    }
    int8_t user = 0;
    flag = TRUE;
    if (a->getAccessInf() == 1) {
        while (flag) {
            first_admin_menu();
            switch (checkInterval(1, 3)) {
            case 1: break;
            case 2: user = 1; flag = FALSE; break;
            case 3: exit(0);
            }
        }
    }
    if(a->getAccessInf() == 0 || user == 1 ){
        while (1) {
            user_menu();
            switch (checkInterval(1, 4)) {
            case 1: game->print_game();
            case 2: break;
            case 3: break;
            case 4: exit(0);
            }
        }
    }

}

