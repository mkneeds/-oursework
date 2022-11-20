#pragma once
#include <iostream>

#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;

inline int checkInt()
{
    int value, counter = 0;
    char* BufForWriting = new char[256];
    cin.clear();
    cin.getline(BufForWriting, 256, '\n');
    for (int i = 0; BufForWriting[i] != '\0'; i++)
        if (isdigit(BufForWriting[i]))
            counter++;
    if (strlen(BufForWriting) != counter ||
        (BufForWriting[0] == '0' && strlen(BufForWriting) > 1))
        value = -1;
    else value = atoi(BufForWriting);
    delete[] BufForWriting;
    return value;
}

inline int checkInterval(int min, int max)
{
    int value;
    value = checkInt();
    while (value < min || value > max)
    {
        cout << "Неккоректный ввод. Повторите попытку->";
        value = checkInt();
    }
    return value;
}

inline void center(int x, int y)
{
    // initialize screen
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    // initialize x and y coordinates
    COORD cursor;
    cursor.X = x;
    cursor.Y = y;

    // set cursor position
    SetConsoleCursorPosition(screen, cursor);
}


inline void color(int code)
{
    HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(text, code);
}
inline void load()
{
    int z = 50;
    cout << '-' << flush;
    while (z != 0)
    {
        z--;
        Sleep(1);
        cout << "\b\\" << flush;
        Sleep(1);
        cout << "\bI" << flush;
        Sleep(1);
        cout << "\b/" << flush;
        Sleep(1);
        cout << "\b-" << flush;
    }

    cout << "\b " << flush;
}