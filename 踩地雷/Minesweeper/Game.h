#ifndef Game_h
#define Game_h

class Game
{
public:
	void Show(char m);
	void SetMineLable(int i, bool left, bool right, bool up, bool down);
	void NoMineAround(int pos);
	bool check();
	void Initially();
	void Touch();

private:
	int map[100];/*地雷盤面*/
	bool mine[100];/*偵測是否採到地雷用*/
	inline int Position(int x, int y) {/*位子函數*/
		return 10 * x + y;
	}

};

#endif
