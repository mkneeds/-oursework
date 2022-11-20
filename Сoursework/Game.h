#pragma once
#include "Table.h"
#include <fstream>
#include <cmath>
#include <istream>
#include <algorithm>
#include <memory>
#include "Machine.h"

using namespace std;

class Game
{
public:
    Game(){}
    Game(int numer_game, string type_of_game, string first_team, string second_team, string time, string kf_1, string kf_x, string kf_2,int money) : numer_game(numer_game), type_of_game(type_of_game),first_team(first_team),second_team(second_team),time(time),kf_1(kf_1),kf_x(kf_x),kf_2(kf_2),money(money){}
    int get_numer() { return numer_game; }
    string get_type() { return type_of_game; }
    string get_first_team() { return first_team; }
    string get_second_team() { return second_team; }
    string get_time() { return time; }
    string get_kf_1() { return kf_1; }
    string get_kf_x() { return kf_x; }
    string get_kf_2() { return kf_2; }
    int get_money() { return money; }
    float get_casino() { return win; }
private:
    float win;
    int numer_game;
    string type_of_game;
    string time;
    string first_team;
    string second_team;
    string kf_1;
    string kf_x;
    string kf_2;
    float money = 0;
    float schet;
public:
    const string NAME_FILE = "Games.txt";
public:
    void print_game();
    void LoadFromFile(vector<Game>& v);
    void add_game();
    void sort_game();
    void filt_game();
    void place_bet(float balance);
    void delete_game();
    void edit_game();
    int get_schet() { return schet; }
    void play_casino(float balance);
private:
    void upload_information();
    void write_end_file();
    void mask_time();
    void mask_kf1();
    void mask_kfx();
    void mask_kf2();
    void BlankBytes(int bytes);

private:
    friend istream& operator>>(istream& stream, Game& v) {
        stream >> v.numer_game;
        stream >> v.type_of_game;
        stream >> v.time;
        stream >> v.first_team;
        stream >> v.second_team;
        stream >> v.kf_1;
        stream >> v.kf_x;
        stream >> v.kf_2;
        stream >> v.money;
        return stream;
    }
    friend ostream& operator<<(ostream& stream, const Game& v) {
        stream << v.numer_game << " " << v.type_of_game<<" "<< v.time << " " << v.first_team << " " << v.second_team << " " << v.kf_1 << " " << v.kf_x << " " << v.kf_2 << " " << v.money;
        return stream;
    }
    Game& operator=(const Game&) = default;
    

    class comp_data {
        int what;
        bool compare(class Game* f, class Game* s) {
            switch (abs(what)) {
            case 1: return f->numer_game < s->numer_game; break;
            case 2: return f->type_of_game < s->type_of_game; break;
            case 3: return f->money < s->money; break;
            default: return false;
            }
        }
    public:
        comp_data(int what) : what(what) {}
        bool operator()( class Game* f, class Game* s) {
            bool ret = compare(f, s);
            return what >= 0 ? ret : !ret;
        }
    };
};
