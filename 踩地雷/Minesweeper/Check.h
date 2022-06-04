#ifndef Check_h
#define Check_h

class Check
{
public:
	void Start();
	bool End();
private:
	int map[100];                               /*地雷盤面*/
	bool mine[100];                         /*偵測是否採到地雷用*/
	inline int Position(int x, int y) {                /*位子函數*/
		return 10 * x + y;
	}

};

#endif
