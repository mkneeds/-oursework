#pragma once
#include "Table.h"
#include <fstream>
#include <cmath>

using namespace std;

class Game
{
    TextTable table;
    const string NAME_FILE = "Games.txt";
    int numer_game;
    string type_of_game;
    string first_team;
    string second_team;
    string time;
    double kf_1;
    double kf_x;
    double kf_2;
public:
    void print_game();
    void add_game();
    void sort_game();
private:
    void upload_information();
    void write_end_file();
};

