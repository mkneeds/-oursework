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
void tokenize(std::string const& str, const char delim,
    std::vector<std::string>& out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}
void Game::filt_game() {
    print_game();
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
    cout << "\t\tМеню фильтрации:" << endl;
    cout << "\t(1) ~ По виду спорта" << endl;
    cout << "\t(2) ~ По команде" << endl;
    cout << "\t(3) ~ По дате(От-До)" << endl;
    cout << "Ваш выбор: ";
    vector<Game> tz;
    LoadFromFile(tz);
    switch (checkIntervals(1, 3)) {
    case 1: {
        string type;
        cout << "Введите вид спорта:";
        getline(cin, type);
        for (int i = 0; i < tz.size(); i++) {
            cout << type << endl;;
            cout << tz[i].type_of_game << endl;
            if (strcmp((tz[i].type_of_game).c_str(), (type.c_str())) == 0) {
                for (int k = 0; tz[i].type_of_game[k]; k++)
                    if (tz[i].type_of_game[k] == '.')
                        tz[i].type_of_game[k] = ' ';
                for (int k = 0; tz[i].first_team[k]; k++)
                    if (tz[i].first_team[k] == '.')
                        tz[i].first_team[k] = ' ';
                for (int k = 0; tz[i].second_team[k]; k++)
                    if (tz[i].second_team[k] == '.')
                        tz[i].second_team[k] = ' ';
                for (int k = 0; tz[i].time[k]; k++)
                    if (tz[i].time[k] == '.')
                        tz[i].time[k] = ' ';
                t.add(to_string(tz[i].numer_game));
                t.add(tz[i].type_of_game);
                t.add(tz[i].time);
                t.add(tz[i].first_team);
                t.add(tz[i].second_team);
                t.add(tz[i].kf_1);
                t.add(tz[i].kf_x);
                t.add(tz[i].kf_2);
                t.add(to_string(tz[i].money));
                t.endOfRow();
            }
            else {
                cout << "Такого вида спорта нет!" << endl;
            }
        }
        system("cls");
        cout << t;
        break;
    }
    case 2: {
        string type;
        cout << "Введите название команды:";
        getline(cin, type);
        cout << type;
        for (int i = 0; i < tz.size(); i++) {
            if (strcmp((tz[i].first_team).c_str(), (type.c_str())) == 0) {
                for (int k = 0; tz[i].type_of_game[k]; k++)
                    if (tz[i].type_of_game[k] == '.')
                        tz[i].type_of_game[k] = ' ';
                for (int k = 0; tz[i].first_team[k]; k++)
                    if (tz[i].first_team[k] == '.')
                        tz[i].first_team[k] = ' ';
                for (int k = 0; tz[i].second_team[k]; k++)
                    if (tz[i].second_team[k] == '.')
                        tz[i].second_team[k] = ' ';
                for (int k = 0; tz[i].time[k]; k++)
                    if (tz[i].time[k] == '.')
                        tz[i].time[k] = ' ';
                t.add(to_string(tz[i].numer_game));
                t.add(tz[i].type_of_game);
                t.add(tz[i].time);
                t.add(tz[i].first_team);
                t.add(tz[i].second_team);
                t.add(tz[i].kf_1);
                t.add(tz[i].kf_x);
                t.add(tz[i].kf_2);
                t.add(to_string(tz[i].money));
                t.endOfRow();
            }
            if (strcmp((tz[i].second_team).c_str(), (type.c_str())) == 0) {
                for (int k = 0; tz[i].type_of_game[k]; k++)
                    if (tz[i].type_of_game[k] == '.')
                        tz[i].type_of_game[k] = ' ';
                for (int k = 0; tz[i].first_team[k]; k++)
                    if (tz[i].first_team[k] == '.')
                        tz[i].first_team[k] = ' ';
                for (int k = 0; tz[i].second_team[k]; k++)
                    if (tz[i].second_team[k] == '.')
                        tz[i].second_team[k] = ' ';
                for (int k = 0; tz[i].time[k]; k++)
                    if (tz[i].time[k] == '.')
                        tz[i].time[k] = ' ';
                t.add(to_string(tz[i].numer_game));
                t.add(tz[i].type_of_game);
                t.add(tz[i].time);
                t.add(tz[i].first_team);
                t.add(tz[i].second_team);
                t.add(tz[i].kf_1);
                t.add(tz[i].kf_x);
                t.add(tz[i].kf_2);
                t.add(to_string(tz[i].money));
                t.endOfRow();
            }
            else {
                cout << "!" << endl;
            }
        }
        cout << t;
        break;
    }
    case 3: {
        cout << "Введите время(**:** **-**-****)" << endl;
        mask_time();
        string first_time = time;
        vector<string>out;
        vector<string>out1;
        vector<string>res;
        const char delim = ':';
        tokenize(first_time, delim, out);
        cout << endl;
        string h1 = out[0];
        string m1 = out[1].substr(0, out[1].find(' '));
        mask_time();
        string next_time = time;
        tokenize(next_time, delim, out1);
        string h2 = out1[0];
        string m2 = out1[1].substr(0, out1[1].find(' '));
        system("cls");
        for (int i = 0; i < tz.size(); i++) {
            res.clear();
            tokenize(tz[i].time, delim, res);
            string hm = res[0];
            string mm = res[1].substr(0, res[1].find(' '));
            bool flag = false;
            int h11 = stoi(h1);
            int hmm = stoi(hm);
            int h22 = stoi(h2);
            if (h11 <= hmm <= h22 && (tz[i].time.find(hmm)>0)) {
                for (int k = 0; tz[i].type_of_game[k]; k++)
                    if (tz[i].type_of_game[k] == '.')
                        tz[i].type_of_game[k] = ' ';
                for (int k = 0; tz[i].first_team[k]; k++)
                    if (tz[i].first_team[k] == '.')
                        tz[i].first_team[k] = ' ';
                for (int k = 0; tz[i].second_team[k]; k++)
                    if (tz[i].second_team[k] == '.')
                        tz[i].second_team[k] = ' ';
                for (int k = 0; tz[i].time[k]; k++)
                    if (tz[i].time[k] == '.')
                        tz[i].time[k] = ' ';
                t.add(to_string(tz[i].numer_game));
                t.add(tz[i].type_of_game);
                t.add(tz[i].time);
                t.add(tz[i].first_team);
                t.add(tz[i].second_team);
                t.add(tz[i].kf_1);
                t.add(tz[i].kf_x);
                t.add(tz[i].kf_2);
                t.add(to_string(tz[i].money));
                t.endOfRow();
            }
            if (stoi(h1) == stoi(h2) && (stoi(m1) <= stoi(mm) <= stoi(m2))) {

            }
        }
        cout << t;
        break;
    }
    }
}
void Game::delete_game() {
    vector<Game>tz;
    vector<Game>tk;
    LoadFromFile(tz);
    print_game();
    int temp;
    cout << "Введите номер записи которую нужно удалить:";
    temp = checkInts();
    int count = 0;
    for (int i = 0; i < tz.size(); i++) {
        if (tz[i].numer_game != temp) {
            tk.push_back(tz[i]);
            ofstream onz(NAME_FILE);
            copy(tk.begin(), tk.end(), ostream_iterator<Game>(onz, "\n"));
            onz.close();
            count = 1;
        }
    }
    if (count == 0) {
        cout << "Записис с таким номером нет..." << endl;
    }
    else {
        cout << "Запись успешно удалена" << endl;
    }
    print_game();
}

void Game::edit_game() {
    vector<Game>tz;

    LoadFromFile(tz);
    print_game();
    int temp;
    cout << "Введите номер записи которую хотите изменить:";
    temp = checkInts();
    int count = 0;
    int index;
    for (int i = 0; i < tz.size(); i++) {
        if (tz[i].numer_game == temp) {
            count = 1;
            index = i;
            break;
       }
    }
    if (count == 0) {
        cout << "Записис с таким номером нет..." << endl;
    }
    else {
        cout << "\t\tМеню редактирования:" << endl;
        cout << "\t(1) ~ Изменить вид спорта" << endl;
        cout << "\t(2) ~ Изменить время" << endl;
        cout << "\t(3) ~ Изменить название первой команды" << endl;
        cout << "\t(4) ~ Изменить название второй команды" << endl;
        cout << "\t(5) ~ Изменить KF_1" << endl;
        cout << "\t(6) ~ Изменить KF_X" << endl;
        cout << "\t(7) ~ Изменить KF_2" << endl;
        cout << "\t(8) ~ Назад" << endl;
        cout << "Ваш выбор: ";
        switch (checkIntervals(1, 7)) {
        case 1: {string type;
            cout << "Введите новый тип игры" << endl;
            getline(cin, type);
            tz[index].type_of_game = type;
            ofstream onz(NAME_FILE);
            copy(tz.begin(), tz.end(), ostream_iterator<Game>(onz, "\n"));
            onz.close();
        }break;
        case 2: {
            string type;
            cout << "Введите новое время" << endl;
            mask_time();
            cout << endl;
            for (int i = 0; time[i]; i++)
                if (time[i] == ' ')
                    time[i] = '.';
            tz[index].time = time;
            ofstream onz(NAME_FILE);
            copy(tz.begin(), tz.end(), ostream_iterator<Game>(onz, "\n"));
            onz.close();
        }break;
        case 3: {
            string type;
            cout << "Введите новое название первой команды" << endl;
            getline(cin, type);
            tz[index].first_team = type;
            ofstream onz(NAME_FILE);
            copy(tz.begin(), tz.end(), ostream_iterator<Game>(onz, "\n"));
            onz.close();
        }break;
        case 4: {
            string type;
            cout << "Введите новое название второй команды" << endl;
            getline(cin, type);
            tz[index].second_team = type;
            ofstream onz(NAME_FILE);
            copy(tz.begin(), tz.end(), ostream_iterator<Game>(onz, "\n"));
            onz.close();
        }break;
        case 5: {
            string type;
            cout << "Введите новой KF_1" << endl;
            mask_kf1();
            cout << endl;
            tz[index].kf_1 = kf_1;
            ofstream onz(NAME_FILE);
            copy(tz.begin(), tz.end(), ostream_iterator<Game>(onz, "\n"));
            onz.close();
        }break;
        case 6: {
            string type;
            cout << "Введите новой KF_X" << endl;
            mask_kfx();
            cout << endl;
            tz[index].kf_x = kf_x;
            ofstream onz(NAME_FILE);
            copy(tz.begin(), tz.end(), ostream_iterator<Game>(onz, "\n"));
            onz.close();
        }break;
        case 7: {
            string type;
            cout << "Введите новой KF_2" << endl;
            mask_kf2();
            cout << endl;
            tz[index].kf_2 = kf_2;
            ofstream onz(NAME_FILE);
            copy(tz.begin(), tz.end(), ostream_iterator<Game>(onz, "\n"));
            onz.close();
        }break;
        }
    }
    print_game();
}