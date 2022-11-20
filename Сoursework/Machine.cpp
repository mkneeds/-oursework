#include "Machine.h"
Wheel::Wheel() {
    srand((int)time(NULL));

    internalPtr = (rand() % 9);

    for (int i = 0; i < 9; i++) {
        slots[i] = i + 1;
    }
}

void Wheel::spin() {
    int spins = (rand() % 50) + 10;

    for (int i = 0; i < spins; i++) {
        internalPtr++;

        if (internalPtr > 8) { internalPtr = 0; }
    }
}


int* Wheel::read() {
    int prev = internalPtr - 1;
    int next = internalPtr + 1;

    if (prev < 0) { prev = 8; }
    if (next > 8) { next = 0; }

    int* values = new int[3];

    values[0] = slots[prev];
    values[1] = slots[internalPtr];
    values[2] = slots[next];

    return values;
}
Machine::Machine() {
    credits = 0;
    betAmount = 0;

    wheels[0] = new Wheel();
    wheels[1] = new Wheel();
    wheels[2] = new Wheel();

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            screen[i][j] = 0;
        }
    }
}


Machine::~Machine() {
    delete(wheels[0]);
    delete(wheels[1]);
    delete(wheels[2]);
}



void Machine::spin() {
    if (betAmount > 0) {
        wheels[0]->spin();
        wheels[1]->spin();
        wheels[2]->spin();

        int* column1 = wheels[0]->read();
        int* column2 = wheels[1]->read();
        int* column3 = wheels[2]->read();


        loadscreen(0, column1);
        loadscreen(1, column2);
        loadscreen(2, column3);

        printscreen();
        checkwinnings();

        betAmount = 0;


        delete[] column1;
        delete[] column2;
        delete[] column3;

        column1 = column2 = column3 = NULL;

    }
    else { cout << "Пожалуйста, сделайте ставку перед вращением." << endl; }
}


void Machine::loadscreen(int col, int* wheelcolumn) {
    for (int i = 0; i < 3; i++) {
        screen[i][col] = wheelcolumn[i];
    }
}



void Machine::printscreen() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
}



void Machine::bet(int lines) {
    if ((lines < 1) || (lines > 5)) {
        cout << "Вы можете делать ставки только на 1 до 5 линий. Пожалуйста, попробуйте снова." << endl;
    }
    else if ((credits - lines) < 0) {
        cout << "Вы имеете->" << credits << " к. Попробуйте добавить больше денег." << endl;
    }
    else {
        betAmount = lines;
        credits -= betAmount;
    }
}



void Machine::insertcoin() {
    credits++;

    cout << "Теперь у вас есть " << credits << " кредитов." << endl;
}


void Machine::insertbill(double billAmount) {
    if ((billAmount >= 1.00) && (billAmount <= 20.00)) {
        int newcredits = (int)(billAmount / .25);
        credits += newcredits;

        cout << "Теперь у вас есть " << credits << " кредитов." << endl;
    }
}


void Machine::checkwinnings() {
    int lineValues[3];
    int winnings = 0;

    if (betAmount >= 1) {
        for (int i = 0; i < 3; i++) {
            lineValues[i] = screen[1][i];
        }

        winnings += checkline(lineValues);
    }

    if (betAmount >= 2) {
        for (int i = 0; i < 3; i++) {
            lineValues[i] = screen[0][i];
        }

        winnings += checkline(lineValues);
    }

    if (betAmount >= 3) {
        for (int i = 0; i < 3; i++) {
            lineValues[i] = screen[2][i];
        }

        winnings += checkline(lineValues);
    }

    if (betAmount >= 4) {
        for (int i = 0; i < 3; i++) {
            lineValues[i] = screen[i][i];
        }

        winnings += checkline(lineValues);
    }

    if (betAmount == 5) {
        for (int i = 2; i >= 0; i--) {
            lineValues[i] = screen[i][i];
        }

        winnings += checkline(lineValues);
    }

    if (winnings > 0) {
        cout << "Вы выиграли " << winnings << " кредитов!" << endl;
        credits += winnings;
    }
    else {
        cout << "Извините, вы ничего не выиграли." << endl;
    }

    cout << "У тебя есть" << credits << "." << endl << endl;
}

int Machine::checkline(int line[3]) {
    if (line[0] == this->luckyseven && line[1] == this->luckyseven && line[2] == this->luckyseven) { return 1000; }
    if (line[0] == this->watermelon && line[1] == this->watermelon && line[2] == this->watermelon) { return 800; }
    if (line[0] == this->triplebar && line[1] == this->triplebar && line[2] == this->triplebar) { return 600; }
    if (line[0] == this->doublebar && line[1] == this->doublebar && line[2] == this->doublebar) { return 500; }
    if (line[0] == this->bar && line[1] == this->bar && line[2] == this->bar) { return 400; }
    if (line[0] == this->cherry && line[1] == this->cherry && line[2] == this->cherry) { return 375; }
    if (line[0] == this->orange && line[1] == this->orange && line[2] == this->orange) { return 350; }
    if (line[0] == this->plum && line[1] == this->plum && line[2] == this->plum) { return 300; }
    if (line[0] == this->luckyseven && line[1] == this->luckyseven) { return 200; }
    if (line[0] == this->cherry && line[1] == this->cherry) { return 50; }
    if (line[0] == this->lemon && line[1] == this->lemon && line[2] == this->lemon) { return 5; }
    return 0;
}