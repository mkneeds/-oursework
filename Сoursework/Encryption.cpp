#include "Encryption.h"

void Encryption::encrypt()
{
    vector<char> cont;
    fstream fin, fout;
    fin.open(file, fstream::in);
    while (fin >> noskipws >> c) {
        __int64 temp = (c + key);
        cont.push_back((char)temp);
    }
    fin.close();
    fout.open(file, fstream::out);
    for (int i = 0; i < cont.size(); i++) {
        fout << cont[i];
    }
    fout.close();
    cont.clear();
}

void Encryption::decrypt()
{
    fstream fin;
    fstream fout;
    fin.open(file, fstream::in);
    vector<char> cont;
    while (fin >> noskipws >> c) {
        __int64 temp = (c - key);
        cont.push_back((char)temp);
    }

    fin.close();
    fout.open(file, fstream::out);
    for (int i = 0; i < cont.size(); i++) {
        fout << cont[i];
    }
    fout.close();
    cont.clear();
}