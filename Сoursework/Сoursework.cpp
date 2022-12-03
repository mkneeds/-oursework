
#include "Authentication.h"
#include <Windows.h>
#include "SmartPointer.cpp"
#include "menu.h"
#include "Game.h"

using namespace menu;

void main(int argc, TCHAR* argv[])
{

    system("color F0");

    HWND console = GetConsoleWindow();
    HMENU menu = GetSystemMenu(console, FALSE);
    HDC mdc = GetDC(console);
    DeleteMenu(menu, SC_CLOSE, MF_BYCOMMAND);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    SmartPointer<Game> game = new Game();
	SmartPointer <Authentication> a = new Authentication();
    graph2();
    bool flag = TRUE;
    bool flag_admin = FALSE;
    while (flag) {
        auth_menu();
        switch (checkInterval(1, 3)) {
        case 1: center(55, 16); flag = a->auth(); system("cls"); break;
        case 2: a->regestration(); break;
        case 3: exit(0);
        }
    }
    flag = TRUE;
    if (a->getAccessInf() == 1) {
        while (flag) {
            first_admin_menu();
            switch (checkInterval(1, 3)) {
            case 1: flag = FALSE;  flag_admin = TRUE;
            {
                bool flag_z = true;
                    while (flag_z) {
                        system("cls");
                        menu::admin_menu();
                        switch (checkInterval(1, 6)) {
                        case 1: system("cls"); game->add_game(); break;
                        case 2: system("cls"); game->delete_game(); system("pause"); break;
                        case 3: system("cls"); game->edit_game(); system("pause"); break;
                        case 4: system("cls"); a->change_user(); break;
                        case 5: system("cls"); game->print_game(); system("pause"); break;
                        case 6: system("cls"); flag_z = false; flag = true; break;
                        }
                }
            }break;
            case 2: flag = FALSE; flag_admin = TRUE; {
                bool flag_z = true;
                while (flag_z) {
                    system("cls");
                    user_menu();
                    switch (checkInterval(1, 6)) {
                    case 1: system("cls"); game->print_game(); sor_fil_menu(); {
                        switch (checkInterval(1, 2)) {
                        case 1: system("cls"); game->sort_game(); system("pause"); break;
                        case 2: system("cls"); game->filt_game(); system("pause"); break;
                        }
                    }; break;
                    case 2: a->upd_balance(); game->place_bet(a->getMoney()); a->upd_Balance(game->get_schet()); system("pause"); break;
                    case 3: a->getBalance(); break;
                    case 4: a->add_balance(); break;
                    case 5: a->upd_balance(); game->play_casino(a->getMoney()); a->upd_Balance(game->get_schet()); a->plus(game->get_casino()); system("pause"); break;
                    case 6: system("cls"); flag_z = false; flag = true; break;
                    }
                }
            
            } break;
            case 3: exit(0);
            }
        }
    }
    if(a->getAccessInf() == 0){
        while (1) {
            system("cls");
            user_menu();
            switch (checkInterval(1, 6)) {
            case 1: system("cls"); game->print_game(); sor_fil_menu(); {
                switch (checkInterval(1, 2)) {
                case 1: system("cls"); game->sort_game(); system("pause"); break;
                case 2: system("cls"); game->filt_game(); system("pause"); break;
                }
            }; break;
            case 2: a->upd_balance(); game->place_bet(a->getMoney()); a->upd_Balance(game->get_schet()); system("pause"); break;
            case 3: a->getBalance(); break;
            case 4: a->add_balance(); break;
            case 5:a->upd_balance(); game->play_casino(a->getMoney()); a->upd_Balance(game->get_schet()); system("pause"); break;
            case 6: exit(0); 
            }
            }
        }
    }

