#include "Game.h"
#include <conio.h>
#include "SmartPointer.cpp"
#include "cassert"


void Game::add_game() {
    setlocale(0, "rus");
    cout << "\t\t\tДобавление игры:" << endl;
    cout << "Сколько хотите добавить игр?" << endl;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "\tВведите тип игры:";
        cin.ignore();
        getline(cin,type_of_game);
        cout<<endl;
        cout << "\tВведите дату начала игры(**:** **-**-****):" << endl;
        mask_time();
        cout << endl;
        cout << "\tВведите имя первой команды:";
        cin.ignore();
        getline(cin, first_team);
        cout << endl;
        cout << "\tВведите имя второй команды:";
        cin.ignore();
        getline(cin,second_team);
        cout << endl;
        cout << "\tВведите коэф. первой команды:";
        mask_kf1();
        cout << endl;
        cout << "\tВведите коэф. при исходе ничья:";
        mask_kfx();
        cout << endl;
        cout << "\tВведите коэф. второй команды:";
        mask_kf2();
        cout << endl;
        upload_information();
        write_end_file();
    }
}
void Game::write_end_file() {
    ofstream fout(NAME_FILE, ios::app);
    for (int i = 0; type_of_game[i]; i++)
        if (type_of_game[i] == ' ')
            type_of_game[i] = '.';
    for (int i = 0; first_team[i]; i++)
        if (first_team[i] == ' ')
            first_team[i] = '.';
    for (int i = 0; second_team[i]; i++)
        if (second_team[i] == ' ')
            second_team[i] = '.';
    for (int i = 0; time[i]; i++)
        if (time[i] == ' ')
            time[i] = '.';
    fout << numer_game << " " << type_of_game << " " << time << " " << first_team << " " << second_team << " " << kf_1 << " " << kf_x << " " << kf_2 << " " << money;
    fout << endl;
    fout.close();
}
void Game::upload_information() {
    ifstream fin(NAME_FILE, ios::in);
    string line;
    numer_game = 1;
    if (!fin) {
        cout << "Не///";
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
        cout << "Не удалось открыть файл...///";
    }
    else {
        TextTable t('-', '|', '+');
        t.add("");
        t.add("Вид спорта");
        t.add("Дата начала игры");
        t.add("Первая команда");
        t.add("Вторая команда");
        t.add("KF_1");
        t.add("KF_X");
        t.add("KF_2");
        t.add("Сумма ставок");
        t.endOfRow();
        while (fout >> numer_game >> type_of_game >> time >> first_team >> second_team >> kf_1 >> kf_x >> kf_2>>money ) {
            for (int i = 0; type_of_game[i]; i++)
                if (type_of_game[i] == '.')
                    type_of_game[i] = ' ';
            for (int i = 0; first_team[i]; i++)
                if (first_team[i] == '.')
                    first_team[i] = ' ';
            for (int i = 0; second_team[i]; i++)
                if (second_team[i] == '.')
                    second_team[i] = ' ';
            for (int i = 0; time[i]; i++)
                if (time[i] == '.')
                    time[i] = ' ';
            t.add(to_string(numer_game));
            t.add(type_of_game);
            t.add(time);
            t.add(first_team);
            t.add(second_team);
            t.add(kf_1);
            t.add(kf_x);
            t.add(kf_2);
            t.add(to_string(money));
            t.endOfRow();
        }
        cout << t;
        fout.close();
    }
}
void Game::mask_time() {
    int length = 0;
    int pospos = 0;
    int posarrays[12] = { 0,1,3,4,6,7,9,10,12,13,14,15 };
    int pos = posarrays[pospos];
    char mask[17] = "**:** **-**-****";
    while (length != 12) {
        int ch = _getch();
        if (ch >= '0' && ch <= '9') {
            length++;
            mask[pos] = ch;
            system("cls");
            pospos++;
            pos = posarrays[pospos];
            cout << mask<<"\b";

        }
    }
    
    time = mask;
}

void Game::mask_kf1() {
    int length = 0;
    int pospos = 0;
    int posarrays[3] = { 0,2 };
    int pos = posarrays[pospos];
    char mask[4] = "*.*";
    while (length != 2) {
        int ch = _getch();
        if (ch >= '0' && ch <= '9') {
            length++;
            mask[pos] = ch;
            system("cls");
            pospos++;
            pos = posarrays[pospos];
            cout << mask;
        }
    }
    kf_1 = mask;
}
void Game::mask_kf2() {
    int length = 0;
    int pospos = 0;
    int posarrays[3] = { 0,2 };
    int pos = posarrays[pospos];
    char mask[4] = "*.*";

    while (length != 2) {
        int ch = _getch();
        if (ch >= '0' && ch <= '9') {
            length++;
            mask[pos] = ch;
            system("cls");
            pospos++;
            pos = posarrays[pospos];
            cout << mask;
        }
    }
    kf_2 = mask;
}
void Game::mask_kfx() {
    int length = 0;
    int pospos = 0;
    int posarrays[3] = { 0,2 };
    int pos = posarrays[pospos];
    char mask[4] = "*.*";
    while (length != 2) {
        int ch = _getch();
        if (ch >= '0' && ch <= '9') {
            length++;
            mask[pos] = ch;
            system("cls");
            pospos++;
            pos = posarrays[pospos];
            cout << mask;
        }
    }
    kf_x = mask;
}
void Game::BlankBytes(int bytes) {
    char strBlankStr[16];
    sprintf_s(strBlankStr, "\r%%%is\r", bytes);
    printf(strBlankStr, "");
}


bool mapFunc(string a, string b)
{
    return a.substr(49) > b.substr(49);
}
int checkInts()
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

int checkIntervals(int min, int max)
{
    int value;
    value = checkInts();
    while (value < min || value > max)
    {
        cout << "Неккоректный ввод. Повторите попытку->";
        value = checkInts();
    }
    return value;
}
void Game::LoadFromFile(vector<Game>&v) {
    ifstream f(NAME_FILE);
    Game temp;
    while (f >> temp){
        v.push_back(temp);
    }
    f.close();

}

void Game::sort_game() {
    vector<Game*> tz;
    vector<Game>tk;
    vector<Game>tk_plus;
    LoadFromFile(tk);
    for (auto item : tk) {
        tz.push_back(new Game(item.get_numer(),item.get_type(),item.get_first_team(),item.get_second_team(),item.get_time(),item.get_kf_1(),item.get_kf_x(),item.get_kf_2(),item.get_money()));
    }

    cout << "\t\tМеню сортировки:" << endl;
    cout << "\t(1) ~ Отсортировать по номеру" << endl;
    cout << "\t(2) ~ Отсортировать по типу" << endl;
    cout << "\t(3) ~ Отсортировать по ставкам" << endl;
    cout << "Ваш выбор: ";
    int what = checkIntervals(-3, 4);
    stable_sort(tz.begin(), tz.end(), comp_data(what));
    tk.clear();
    
    for (auto item : tz) {
        tk_plus.push_back(*item);
    }

    ofstream onz(NAME_FILE);
    copy(tk_plus.begin(), tk_plus.end(), ostream_iterator<Game>(onz, "\n"));
    onz.close();
    print_game();
    tk.clear();
    tz.clear();
    tk_plus.clear();
}