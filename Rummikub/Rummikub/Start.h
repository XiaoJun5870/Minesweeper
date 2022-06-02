#ifndef Start_h
#define Start_h
#include "card.h"
class Start {
private:
	int first;
	card hc_arr[14];
public:
	void setFirst(int);
	void setHc(card);
	int getFirst();
	int getHc();
};
#endif
