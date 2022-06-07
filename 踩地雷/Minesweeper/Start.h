#ifndef Start_h
#define Start_h

class Start
{
public:
	void start();
	bool end();
private:
	int map[100];/*地雷版面*/
	bool mine[100];/*偵測是否採到地雷用*/
	inline int Position(int x, int y) {/*位子函數*/
		return 10 * x + y;
	}

};

#endif
