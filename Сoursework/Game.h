#pragma once
#include "Table.h"
#include <fstream>
#include <cmath>
#include <istream>
#include <algorithm>
#include <memory>

using namespace std;

class Game
{
//public:
//    vector<Game>tz;
//    Game();
//    Game(const Game&) = default;
//    Game(int numer_game, string type_of_game, string first_team, string second_team, string time, string kf_1, string kf_x, string kf_2, int money) {
//        tz.push_back(*this);
//    }
private:
    TextTable table;
    const string NAME_FILE = "Games.txt";
    int numer_game;
    string type_of_game;
    string first_team;
    string second_team;
    string time;
    string kf_1;
    string kf_x;
    string kf_2;
    int money = 0;
public:
    void print_game();
    void add_game();
    void sort_game();
    void filt_game();
    void make_money();
private:
    void upload_information();
    void write_end_file();
    void mask_time();
    void mask_kf1();
    void mask_kfx();
    void mask_kf2();
    void BlankBytes(int bytes);
    void LoadFromFile(vector<Game>& v);
private:
    struct comp_data {
        int what;
        bool compare(const class Game& f, const class Game& s) {
            switch (abs(what)) {
            case 1: return f.numer_game < s.numer_game; break;
            case 2: return f.type_of_game < s.type_of_game; break;
            case 3: return f.first_team < s.first_team; break;
            case 4: return f.second_team < s.second_team; break;
            case 5: return f.time < s.time; break;
            case 6: return f.money < s.money; break;
            default: return false;
            }
        }
    public:
        comp_data(int what) : what(what) {}
        bool operator()(const class Game& f, const class Game& s) {
            bool ret = compare(f, s);
            return what >= 0 ? ret : !ret;
        }
    };
    friend istream& operator>>(istream& stream, Game& v) {
        stream >> v.numer_game;
        stream >> v.type_of_game;
        stream >> v.first_team;
        stream >> v.second_team;
        stream >> v.time;
        stream >> v.kf_1;
        stream >> v.kf_x;
        stream >> v.kf_2;
        stream >> v.money;
        return stream;
    }
    friend ostream& operator<<(ostream& stream, Game& v) {
        stream << v.numer_game;
        stream << v.type_of_game;
        stream << v.first_team;
        stream << v.second_team;
        stream << v.time;
        stream << v.kf_1;
        stream << v.kf_x;
        stream << v.kf_2;
        stream << v.money;
        return stream;
    }
    Game &operator=(const Game&) = default;
};

