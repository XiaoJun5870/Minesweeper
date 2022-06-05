#include<iostream>
#include<cmath>
#include<ctime>
#include "Game.h"
#include "Start.h"
using namespace std;
void Start::start() {                                 /*開始遊戲*/
    Game c;
    c.Initially();
    bool notboom = true;
    while (notboom) {
        c.Show(' ');
        c.Touch();
        notboom = c.check();
    }
    return;
}

bool Start::end() {                                   /*結束遊戲*/
    char answer;
    cout << "Do you want to play again?(y/n)";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
        system("cls");
        return true;
    }
    else if (answer == 'n' || answer == 'N')return false;
    else cout << "Wrong answer"; return false;
}
