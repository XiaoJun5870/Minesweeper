#include<iostream>
#include<cmath>
#include<ctime>
#include "Game.h"
#include "Start.h"
using namespace std;


void Game::Show(char m) {/*顯示版面*/

    cout << "  0123456789\n +----------+\n";/*地圖框架*/
    for (int x = 0; x < 10; x++) {
        cout << x << '|';
        for (int y = 0; y < 10; y++) {
            if (mine[Position(x, y)])
                if (map[Position(x, y)] == -1)
                    cout << m;
                else cout << map[Position(x, y)];
            else cout << ' ';
        }
        cout << '|' << '\n';/*地圖框架*/
    }
    cout << " +----------+\n";/*地圖框架*/
    return;/*重複執行*/
}

void Game::SetMineLable(int i, bool left, bool right, bool up, bool down) {/*周圍地雷數量*/
    if (!up) {
        if ((map[i - 11] != -1) && !left)
            map[i - 11]++;
        if (map[i - 10] != -1)
            map[i - 10]++;
        if ((map[i - 9] != -1) && !right)
            map[i - 9]++;
    }
    if ((map[i - 1] != -1) && !left)
        map[i - 1]++;
    if ((map[i + 1] != -1) && !right)
        map[i + 1]++;
    if (!down) {
        if ((map[i + 9] != -1) && !left)
            map[i + 9]++;
        if (map[i + 10] != -1)
            map[i + 10]++;
        if ((map[i + 11] != -1) && !right)
            map[i + 11]++;
    }
}
void Game::NoMineAround(int p) {/*連鎖*/
    bool l = (p % 10 == 0) ? true : false,
        r = (p % 10 == 9) ? true : false,
        u = (p / 10 == 0) ? true : false,
        d = (p / 10 == 9) ? true : false;
    if (!u) {
        if (!mine[p - 11] && !l) {
            mine[p - 11] = true;
            if (map[p - 11] == 0)
                NoMineAround(p - 11);
        }
        if (!mine[p - 10]) {
            mine[p - 10] = true;
            if (map[p - 10] == 0)
                NoMineAround(p - 10);
        }
        if (!mine[p - 9] && !r) {
            mine[p - 9] = true;
            if (map[p - 9] == 0)
                NoMineAround(p - 9);
        }
    }
    if (!mine[p - 1] && !l) {
        mine[p - 1] = true;
        if (map[p - 1] == 0)
            NoMineAround(p - 1);
    }
    if (!mine[p + 1] && !r) {
        mine[p + 1] = true;
        if (map[p + 1] == 0)
            NoMineAround(p + 1);
    }
    if (!d) {
        if (!mine[p + 11] && !r) {
            mine[p + 11] = true;
            if (map[p + 11] == 0)
                NoMineAround(p + 11);
        }
        if (!mine[p + 10]) {
            mine[p + 10] = true;
            if (map[p + 10] == 0)
                NoMineAround(p + 10);
        }
        if (!mine[p + 9] && !l) {
            mine[p + 9] = true;
            if (map[p + 9] == 0)
                NoMineAround(p + 9);
        }
    }    return;/*重複執行*/
}
bool Game::check() {/*檢查勝利或失敗條件是否滿足*/
    register short set = 0;
    for (short i = 0; i < 100; i++) {
        if ((mine)) {
            set++;
            if (map[i] == -1) {
                for (short a = 0; a < 100; a++) {
                    if (map[a] == -1)
                        mine[a] = true;
                }
                Show('*');/*秀出所有地雷*/
                cout << "\tGame over!\n";
                return false;
            }
        }
    }
    if (set == 90) {
        for (short a = 0; a < 100; a++) {
            mine[a] = true;
        }
        Show('M');/*秀出所有地雷*/
        cout << "\tCongratulations!!\n";
        return false;
    }
    else return true;
}
void Game::Initially() {/*初始化盤面*/
    for (int i = 0; i < 100; i++) {
        map[i] = 0;
        mine[i] = false;
    }
    Show(' ');/*秀出地圖*/
    unsigned int x, y;
    cin >> x >> y;/*輸入座標*/
    system("cls");
    if (x > 10 || y > 10)
        cout << "Wrong position\n";
    else
        mine[Position(x, y)] = true;
    srand(time(0));/*隨機*/
    int mine_number = 0;
    bool l, r, u, d;
    while (mine_number < 10) {
        int a = (int)((float)rand() / 32768L * 100L);
        if (a == Position(x, y)) continue;
        l = (a % 10 == 0) ? true : false;
        r = (a % 10 == 9) ? true : false;
        u = (a / 10 == 0) ? true : false;
        d = (a / 10 == 9) ? true : false;
        if (map[a] != -1) {
            map[a] = -1;
            SetMineLable(a, l, r, u, d);
            mine_number++;
        }
    }
    if (map[Position(x, y)] == 0) NoMineAround(Position(x, y));
    return;/*重複執行*/
}

void Game::Touch() {/*踩*/
    unsigned int x, y;
    cin >> x >> y;
    system("cls");
    if (x > 10 || y > 10)/*超出地圖*/
        cout << "Wrong position\n";
    else
        mine[Position(x, y)] = true;
    if (map[Position(x, y)] == 0) NoMineAround(Position(x, y));
    return;/*重複執行*/
}
