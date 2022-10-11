#include "Game.h"

void Game::add_game() {
    cout << "\t\t\t���������� ������:" << endl;
    cout << "������� ������ ������ ��������?" << endl;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "\t������� ��� ������:";
        cin >> type_of_game;
        cin.get();
        cout<<endl;
        cout << "\t������� ����� ������ ����:";
        cin >> time;
        cin.get();
        cout << endl;
        cout << "\t������� �������� ������ �������:";
        getline(cin,first_team);
        cout << endl;
        cout << "\t������� �������� ������ �������:";
        getline(cin, second_team);
        cout << endl;
        cout << "\t������� ����. �� ������ �������:";
        cin >> kf_1;
        cin.get();
        cout << endl;
        cout << "\t������� ����. ��� ������ �����:";
        cin >> kf_x;
        cin.get();
        cout << endl;
        cout << "\t������� ����. �� ������ �������:";
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
        cout << "��� ������� � �����,���������� � ������///";
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
        cout << "��� ������� � �����,���������� � ������///";
    }
    else {
        TextTable t('-', '|', '+');
        t.add("�");
        t.add("��� ������");
        t.add("������ ����");
        t.add("������ �������");
        t.add("������ �������");
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