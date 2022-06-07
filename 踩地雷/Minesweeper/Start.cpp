#include<iostream>
#include<cmath>
#include<ctime>
#include "Game.h"
#include "Start.h"
using namespace std;
void Start::start() {/*開始遊戲*/
    Game c;
    c.Initially();/*初始化盤面*/
    bool notboom = true;
    while (notboom) {/*沒有地雷*/
        c.Show(' ');/*空氣*/
        c.Touch();/*踩*/
        notboom = c.check();/*沒有地雷->檢查*/
    }
    return;
}

bool Start::end() {/*結束遊戲*/
    char answer;
    cout << "Do you want to play again?(y/n)";/*在玩一次?*/
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {/*【是/否】*/
        system("cls");
        return true;
    }
    else if (answer == 'n' || answer == 'N')return false;
    else cout << "Wrong answer"; return false;
}
