#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

int map[100];                               /*�a�p�L��*/
bool map_info[100];                         /*�����O�_�Ĩ�a�p��*/
inline int Pos(int x, int y) {                /*��l���*/
    return 10 * x + y;
}


void ShowMap(char m) {                             /*��ܽL��*/
    cout << "  0123456789\n +----------+\n";
    for (int x = 0; x < 10; x++) {
        cout << x << '|';
        for (int y = 0; y < 10; y++) {
            if (map_info[Pos(x, y)])
                if (map[Pos(x, y)] == -1)
                    cout << m;
                else cout << map[Pos(x, y)];
            else cout << ' ';
        }
        cout << '|' << '\n';
    }
    cout << " +----------+\n";
    return;
}
/*�P��a�p�Ƴ]�w*/
void SetMineLable(int i, bool left, bool right, bool up, bool down) {
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
void NoMineAround(int pos) {
    bool l = (pos % 10 == 0) ? true : false,
        r = (pos % 10 == 9) ? true : false,
        u = (pos / 10 == 0) ? true : false,
        d = (pos / 10 == 9) ? true : false;
    if (!u) {
        if (!map_info[pos - 11] && !l) {
            map_info[pos - 11] = true;
            if (map[pos - 11] == 0)
                NoMineAround(pos - 11);
        }
        if (!map_info[pos - 10]) {
            map_info[pos - 10] = true;
            if (map[pos - 10] == 0)
                NoMineAround(pos - 10);
        }
        if (!map_info[pos - 9] && !r) {
            map_info[pos - 9] = true;
            if (map[pos - 9] == 0)
                NoMineAround(pos - 9);
        }
    }
    if (!map_info[pos - 1] && !l) {
        map_info[pos - 1] = true;
        if (map[pos - 1] == 0)
            NoMineAround(pos - 1);
    }
    if (!map_info[pos + 1] && !r) {
        map_info[pos + 1] = true;
        if (map[pos + 1] == 0)
            NoMineAround(pos + 1);
    }
    if (!d) {
        if (!map_info[pos + 11] && !r) {
            map_info[pos + 11] = true;
            if (map[pos + 11] == 0)
                NoMineAround(pos + 11);
        }
        if (!map_info[pos + 10]) {
            map_info[pos + 10] = true;
            if (map[pos + 10] == 0)
                NoMineAround(pos + 10);
        }
        if (!map_info[pos + 9] && !l) {
            map_info[pos + 9] = true;
            if (map[pos + 9] == 0)
                NoMineAround(pos + 9);
        }
    }    return;
}

void Init() {                                /*��l�ƽL��*/
    for (int i = 0; i < 100; i++) {
        map[i] = 0;
        map_info[i] = false;
    }
    ShowMap(' ');
    unsigned int x, y;
    cin >> x >> y;
    system("cls");
    if (x > 10 || y > 10)
        cout << "Wrong position\n";
    else
        map_info[Pos(x, y)] = true;
    srand(time(0));
    int mine_number = 0;
    bool l, r, u, d;
    while (mine_number < 10) {
        int a = (int)((float)rand() / 32768L * 100L);
        if (a == Pos(x, y)) continue;
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
    if (map[Pos(x, y)] == 0) NoMineAround(Pos(x, y));
    return;
}

void Touch() {                                 /*��*/
    unsigned int x, y;
    cin >> x >> y;
    system("cls");
    if (x > 10 || y > 10)
        cout << "Wrong position\n";
    else
        map_info[Pos(x, y)] = true;
    if (map[Pos(x, y)] == 0) NoMineAround(Pos(x, y));
    return;
}

bool Check() {                                 /*�ˬd�ӧQ�Υ��ѱ���O�_����*/
    register short set = 0;
    for (short i = 0; i < 100; i++) {
        if ((map_info)) {
            set++;
            if (map[i] == -1) {
                for (short a = 0; a < 100; a++) {
                    if (map[a] == -1)
                        map_info[a] = true;
                }
                ShowMap('*');
                cout << " Game over!\n";
                return false;
            }
        }
    }
    if (set == 90) {
        for (short a = 0; a < 100; a++) {
            map_info[a] = true;
        }
        ShowMap('M');
        cout << " Congratulations!!\n";
        return false;
    }
    else return true;
}
void Start() {                                 /*�}�l�C��*/
    Init();
    bool not_boom = true;
    while (not_boom) {
        ShowMap(' ');
        Touch();
        not_boom = Check();
    }
    return;
}
bool End() {                                   /*�����C��*/
    char command;
    cout << "Do you want to play again?(y/n)";
    cin >> command;
    if (command == 'y' || command == 'Y') {
        system("cls");
        return true;
    }
    else if (command == 'n' || command == 'N')return false;
    else cout << "Wrong command";
}

int main() {
    bool play = true;
    while (play) {
        Start();
        play = End();
    }
    return 0;
}