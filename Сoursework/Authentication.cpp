#include "Authentication.h"
#include <Windows.h>
#include "Table.h"
void Authentication::regestration() {
    system("cls");
    if (account_point == 0) {
        string login;
        string login_check_povtor;
        int controller = 0;
        ifstream fout(file);
        center(35, 14);
        cout << "\t\t�����������:" << endl;
        center(35, 15);
        cout << "������� �����:";
        login = setLogin();
        if (!fout.is_open()) {
            cout << "�� ������ ������� ��...���������� � ��������������" << endl;
        }
        else {
            while (!fout.eof()) {
                enc.decrypt();
                fout >> login_check_povtor;
                enc.encrypt();
                if (strcmp(login_check_povtor.c_str(), login.c_str()) != 0) {
                    controller = 0;
                }
                else {
                    controller = 1;
                    break;
                }
            }
        }
        if (controller == 0) {
            center(35, 16);
            cout << "������� ������:";
            setPassword();
            account_point = 1;
            writeEndFileAccounts();
            system("cls");
            center(35, 10);
            cout << "Loading ";
            load();
            system("cls");
            cout << "����������� ������ �������" << endl;
            system("cls");
        }
        else {
            fout.close();
            system("cls");
            center(35, 10);
            cout << "Loading ";
            load();
            cout << "����� ����� ��� ���������� ��������� �������...." << endl;
            system("pause");
            system("cls");
        }

    }
    else {
        system("cls");
        center(35, 10);
        cout << "Loading ";
        load();
        cout << "�� ��� ������� �������...�������������" << endl;
        system("pause");
        system("cls");
    }
}
void Authentication::writeEndFileAccounts()
{
	enc.decrypt();
	ofstream fout(file, ios::app);
	fout << login << " " << password << " " << role << " "<<user_balance;
	fout << endl;
	fout.close();
	enc.encrypt();
}
string Authentication::setLogin() {
	int controller;
	string BufForWriting;
	char symbols[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm._-1234567890";
	do {
		controller = 0;
		cin.clear();
		getline(cin,BufForWriting);
		if (BufForWriting.size() < 6)
		{
            center(35, 18);
			cout << "����� ������ ��������� 6 ��� ����� ��������: ";
			controller = 1;
		}
		else
		{
			for (register int i = 0; BufForWriting[i] != '\0'; i++)
			{
				controller = 2;
				for (register int j = 0; symbols[j] != '\0'; j++)
				{
					if (BufForWriting[i] == symbols[j]) { controller = 0; break; }
				}
				if (controller == 2)
				{
                    center(35, 18);
					cout << "����� ����� ��������� ��������� �����, ����� � ����������� �������(-._): ";
					break;
				}
			}
		}
	} while (controller != 0);
	login = BufForWriting;
	return login;
}
string Authentication::setPassword() {
	string BufForWriting;
	int controller, num, alpha;
	do {
		cin.clear();
		BufForWriting = encryption();
		controller = 0; alpha = 0; num = 0;
		if (BufForWriting.size() < 8)
		{
            center(35, 18);
			cout << "\n������ ������ ��������� 8 ��� ����� ��������: \n";
			controller = -1;
		}
		else
		{
			for (register int i = 0; BufForWriting[i] != '\0'; i++)
			{
				if (isspace(BufForWriting[i]))
				{
                    center(35, 18);
					cout << "\n������ �� ������ ��������� �������: \n";
					controller = -1;
					break;
				}
				else if (isdigit(BufForWriting[i]))
					num++;
				else if (isalpha(BufForWriting[i]))
					alpha++;
			}
			if (controller != -1 && (num == 0 || alpha == 0))
			{
                center(35, 18);
				cout << "\n������ ������ ��������� ����� � �����: \n";
				controller = -1;
			}
		}
	} while (controller == -1);
	password = BufForWriting;
	return BufForWriting;
}

char* Authentication::encryption() {
	char a[254];
	register int8_t i;
	for (i = 0; (a[i] = _getch()) != '\r';)
	{
		if (a[i] == '\b' && i != 0)
		{
			printf("\b \b");
			i--;
		}
		else if (a[i] != '\b')
		{
			printf("*");
			i++;
		}
	}
	a[i] = '\0';
	return a;
}

void Authentication::change_user()
{
    bool flag;
    system("cls");
    vector<Authentication> user;
    vector<Authentication> new_user;
    upload_information(user);
    TextTable t;
    t.add("�����");
    t.add("������");
    t.add("����");
    t.add("������");
    t.endOfRow();
    for (int i = 0;i<user.size(); i++) {
        t.add(user[i].login);
        t.add(user[i].password);
        t.add(user[i].role);
        t.add(to_string(user[i].user_balance));
        t.endOfRow();
    }
    cout << t;
    cout << "������� ����� ������������ ������� ������ ��������:" << endl;
    string login;
    cin >> login;
    for (int i = 0; i < user.size(); i++) {
        if (user[i].login == login) {
            int index = i;
            system("cls");
            cout << "\t\t��� ������ ��������?" << endl;
            cout << "\t(1) ~ ������� ������������" << endl;
            cout << "\t(2) ~ ���� ������ ������/�����" << endl;
            cout << "\t(3) ~ �������� ������" << endl;
            cout << "\t(4) ~ �����" << endl;
            cout << "\t��� �����:";
            int choose;
            cin >> choose;
            switch(choose) {
            case 1: {
                for (int i = 0; i < user.size(); i++) {
                    if (index != i) {
                        new_user.push_back(user[i]);
                    }
                }
                enc.decrypt();
                ofstream onz(file);
                copy(new_user.begin(), new_user.end(), ostream_iterator<Authentication>(onz, "\n"));
                onz.close();
                enc.encrypt();
            }break;
            case 2: {
                if (strcmp(user[index].role.c_str(), "User") == 0) {
                    user[index].role = "Admin";
                    enc.decrypt();
                    ofstream onz(file);
                    copy(user.begin(), user.end(), ostream_iterator<Authentication>(onz, "\n"));
                    onz.close();
                    enc.encrypt();
                }
                else {
                    user[index].role = "User";
                    enc.decrypt();
                    ofstream onz(file);
                    copy(user.begin(), user.end(), ostream_iterator<Authentication>(onz, "\n"));
                    onz.close();
                    enc.encrypt();
                }
            }break;
            case 3: {
                cout << "������� �������� ������ ��� ������������:";
                float money;
                cin >> money;
                user[i].user_balance = money;
                ofstream onz(file);
                copy(user.begin(), user.end(), ostream_iterator<Authentication>(onz, "\n"));
                onz.close();
                enc.encrypt();
            }break;
            case 4:  break;
            default: break;
            }
        }
        else {
            flag = true;
        }
    }
    if (flag)
        cout << "������ ������������ ���!" << endl;
}

int Authentication::auth() {
	enc.decrypt();
	ifstream fin(file, ios::in);
	if (fin.peek() == EOF) {
        system("cls");
        center(45, 12);
        color(177);
		cout << "�� ��������� ������ ������������� ���������!" << endl;
        center(35, 13);
        color(177);
		cout << "������� �����:";
		login = setLogin();
        center(35, 14);
        color(177);
		cout << "������� ������:";
		password = setPassword();
		role = "Admin";
		account_point = 1;
		writeEndFileAccounts();
		fin.close();       
        system("cls");
        center(35, 10);
        cout << "Loading ";
        load();
        cout << "����������� ������ �������" << endl;
        system("pause");
        return account_point;
	}
	else {
        system("cls");
        center(45, 12);
        color(177);
        cout << "�����������:" << endl;
		int8_t controller = 0, autho = 0, access = 0;
        center(35, 13);
        color(177);
		cout << "Login: ";
		login = setLogin();
        center(35, 14);
		cout << "Password: ";
		password = setPassword();
		cout << endl;
		ifstream fin(file, ios::in);
		string checher_login;
		string checher_password;
		string checher_role;
		fin.seekg(0, ios::beg);
		if (!fin) {
			cout << "��� ������� � �����,���������� � ������///";
		}
		else {
			while (strcmp(checher_login.c_str(), login.c_str()) != 0 && !fin.eof()) {
				fin >> checher_login;
				if (strcmp(login.c_str(), checher_login.c_str()) == 0) {
					fin >> checher_password;
					controller = 0;
				}
				else {
					controller = 1;
				}
			}
			if (strcmp(password.c_str(), checher_password.c_str()) != 0) {
				controller = 1;
			}
			else {
				fin >> checher_role;
			}
			if (controller == 1) {
				cout << "����� ��� ������ ������� �������.��������� �������" << endl;
				system("pause");
				access_log = 0;
                enc.encrypt();
                return TRUE;
			}
			else {
				string admin = "Admin";
				if (strcmp(checher_role.c_str(), admin.c_str()) == 0) {
					access_inf = 1;
				}
				else {
					access_inf = 0;
				}
				access_log = 1;
                upd_balance();
                system("cls");
       
                system("cls");
                center(35, 10);
                cout << "Loading ";
                load();
                system("cls");
                center(35, 14);
                cout << "�� ������� ��������������.." << endl;
                enc.encrypt();
                return FALSE;
			}

		}
        fin.close();
	}
    fin.close();
}
void Authentication::upload_information(vector<Authentication> &v) {
    enc.decrypt();
    ifstream f(file);
    Authentication temp;
    while (f >> temp) {
          v.push_back(temp);
     }
      f.close();
      enc.encrypt();
}

void Authentication::upd_balance() {
    vector <Authentication>cont;
    upload_information(cont);
    for (int i = 0; i < cont.size(); i++) {
        if (cont[i].login == login) {
            user_balance = cont[i].user_balance;
        }
    }
}
void Authentication::upd_Balance(float money) {
    vector <Authentication>cont;
    upload_information(cont);
    for (int i = 0; i < cont.size(); i++) {
        if (cont[i].login == login) {
            cont[i].user_balance = user_balance - money;
        }
    }
    enc.decrypt();
    ofstream onz(file);
    copy(cont.begin(), cont.end(), ostream_iterator<Authentication>(onz, "\n"));
    onz.close();
    enc.encrypt();
}
void Authentication::plus(float money) {
    vector <Authentication>cont;
    upload_information(cont);
    for (int i = 0; i < cont.size(); i++) {
        if (cont[i].login == login) {
            cont[i].user_balance = user_balance + money;
        }
    }
    enc.decrypt();
    ofstream onz(file);
    copy(cont.begin(), cont.end(), ostream_iterator<Authentication>(onz, "\n"));
    onz.close();
    enc.encrypt();
}
void Authentication::add_balance() {
    try {
        cout << "������� ��������(������:79927398713):" << endl;
        string name_card;
        cin >> name_card;
        if (!checkLuhn(name_card)) {
            throw name_card;
        }
        cout << "������� CCV";
        string ccv;
        cin >> ccv;
    }
    catch(string name_card) {
        cout << "�������� �� �������..." << endl;
        cout << "������� ��������(������:79927398713):" << endl;
        cin >> name_card;
        cout << "������� CCV";
        string ccv;
        cin >> ccv;
    }
    cout << "����� ��� ����������:" << endl;
    int sum;
    cin >> sum;
    user_balance += sum;
    vector <Authentication>cont;
    upload_information(cont);
    for (int i = 0; i < cont.size(); i++) {
        if (cont[i].login == login) {
            cont[i].user_balance = user_balance;
        }
    }
    enc.decrypt();
    ofstream onz(file);
    copy(cont.begin(), cont.end(), ostream_iterator<Authentication>(onz, "\n"));
    onz.close();
    enc.encrypt();
}
bool Authentication::checkLuhn(const string& cardNo) {
    int nDigits = cardNo.length();

    int nSum = 0, isSecond = false;
    for (int i = nDigits - 1; i >= 0; i--) {

        int d = cardNo[i] - '0';

        if (isSecond == true)
            d = d * 2;
        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}
