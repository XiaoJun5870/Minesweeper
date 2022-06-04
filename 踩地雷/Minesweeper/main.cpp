#include<iostream>
#include<cmath>
#include<ctime>
#include "Game.h"
using namespace std;

int main() {
    bool play = true;
    Game a;
    while (play) {
        a.Start();
        play = a.End();
    }
    return 0;
}
