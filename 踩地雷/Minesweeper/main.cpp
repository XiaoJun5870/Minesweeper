#include<iostream>
#include<cmath>
#include<ctime>
#include "Game.h"
#include "Check.h"
using namespace std;

int main() {
    bool play = true;
    Game a;
    Check b;
    while (play) {
        b.Start();
        play = b.End();
    }
    return 0;
}
