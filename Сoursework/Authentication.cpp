#include "Authentication.h"

void Authentication::regestration() {
	cout << "\t\t�����������:" << endl;
	cout << "������� �����:" << endl;
	setLogin();
	cout << "������� ������:" << endl;
	setPassword();
	writeEndFileAccounts();
	

}
void Authentication::writeEndFileAccounts()
{
	enc.decrypt();
	ofstream fout(file, ios::app);
	fout << login << " " << password << " " << role;
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
			cout << "\n������ ������ ��������� 8 ��� ����� ��������: \n";
			controller = -1;
		}
		else
		{
			for (register int i = 0; BufForWriting[i] != '\0'; i++)
			{
				if (isspace(BufForWriting[i]))
				{
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

void Authentication::auth() {
	enc.decrypt();
	ifstream fin(file, ios::in);
	if (fin.peek() == EOF) {
		cout << "�� ��������� ������ ������������� ���������!" << endl;
		cout << "������� �����:" << endl;
		login = setLogin();
		cout << "������� ������:" << endl;
		password = setPassword();
		role = "Admin";
		access_reg = 0;
		writeEndFileAccounts();
		fin.close();
	}
	else {
		int8_t controller = 0, autho = 0, access = 0;
		cout << "Login: ";
		login = setLogin();
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
			}
			else {
				string admin = "Admin";
				if (strcmp(checher_role.c_str(), admin.c_str()) == 0) {
					access_inf = 1;
				}
				else {
					access_inf = 0;
				}
				cout << "�� ������� �����...." << endl;
				access_log = 1;
				system("pause");
			}

		}
		fin.close();
		enc.encrypt();
	}
}