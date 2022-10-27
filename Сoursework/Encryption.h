#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Encryption
{
    __int64 key = 243234283834;
    string file = "Auth.txt";
    char c;
public:
    void encrypt();
    void decrypt();

};

