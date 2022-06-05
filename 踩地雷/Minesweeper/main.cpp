#include<iostream>
#include<cmath>
#include<ctime>
#include "Game.h"
#include "Start.h"
using namespace std;

int main() {
    bool play = true;
    Start b;
    while (play) {
        b.start();
        play = b.end();
    }
    return 0;
}
