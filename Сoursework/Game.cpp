#include "Game.h"

void Game::add_game() {
    cout << "\t\t\tДобавление матчей:" << endl;
    cout << "Сколько матчей хотите добавить?" << endl;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "\tВведите вид спорта:";
        cin >> type_of_game;
        cin.get();
        cout<<endl;
        cout << "\tВведите время начала игры:";
        cin >> time;
        cin.get();
        cout << endl;
        cout << "\tВведите название первой команды:";
        getline(cin,first_team);
        cout << endl;
        cout << "\tВведите название второй команды:";
        getline(cin, second_team);
        cout << endl;
        cout << "\tВведите коэф. на первую команду:";
        cin >> kf_1;
        cin.get();
        cout << endl;
        cout << "\tВведите коэф. при исходе ничья:";
        cin >> kf_x;
        cin.get();
        cout << endl;
        cout << "\tВведите коэф. на вторую команду:";
        cin >> kf_2;
        cin.get();
        cout << endl;
        upload_information();
        write_end_file();
    }
}
void Game::write_end_file() {
    ofstream fout(NAME_FILE, ios::app);
    for (int i = 0; first_team[i]; i++)
        if (first_team[i] == ' ')
            first_team[i] = '.';
    for (int i = 0; second_team[i]; i++)
        if (second_team[i] == ' ')
            second_team[i] = '.';
    fout << numer_game << " " << type_of_game << " " << time << " " << first_team << " " << second_team << " " << kf_1 << " " << kf_x << " " << kf_2;
    fout << endl;
    fout.close();
}
void Game::upload_information() {
    ifstream fin(NAME_FILE, ios::in);
    string line;
    numer_game = 1;
    if (!fin) {
        cout << "Нет доступа к файлу,обратитесь к админу///";
        }
    else {
        while (getline(fin, line)) {
        numer_game++;
      }
   }
   fin.close();    
}
void Game::print_game() {
    ifstream fout(NAME_FILE, ios::in);
    if (!fout) {
        cout << "Нет доступа к файлу,обратитесь к админу///";
    }
    else {
        TextTable t('-', '|', '+');
        t.add("№");
        t.add("Вид Спорта");
        t.add("Начало игры");
        t.add("Первая команда");
        t.add("Вторая команда");
        t.add("KF_1");
        t.add("KF_X");
        t.add("KF_2");
        t.endOfRow();
        while (fout >> numer_game >> type_of_game >> time >> first_team >> second_team >> kf_1 >> kf_x >> kf_2) {
            for (int i = 0; first_team[i]; i++)
                if (first_team[i] == '.')
                    first_team[i] = ' ';
            for (int i = 0; second_team[i]; i++)
                if (second_team[i] == '.')
                    second_team[i] = ' ';
            
            t.add(to_string(numer_game));
            t.add(type_of_game);
            t.add(time);
            t.add(first_team);
            t.add(second_team);
            t.add(to_string(kf_1));
            t.add(to_string(kf_x));
            t.add(to_string(kf_2));
            t.endOfRow();
        }
        cout << t;
        fout.close();
    }
}