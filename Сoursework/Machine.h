#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Wheel {
public:
    Wheel();
    void spin();
    int* read();

private:
    int slots[9];
    int internalPtr;
};


class Machine {
public:
    enum Image {
        orange = 1,
        watermelon,
        luckyseven,
        lemon,
        bar,
        doublebar,
        triplebar,
        cherry,
        plum
    };

    Machine();
    ~Machine();
    void spin();
    void bet(int);
    void insertcoin();
    void insertbill(double);
    void printscreen();
    int get_modey() { return credits = credits / 20; }

private:
    void loadscreen(int, int*);
    void checkwinnings();
    int checkline(int line[3]);
    int credits;
    int betAmount;
    int screen[3][3];

    Wheel* wheels[3];
};



