#ifndef Crad_h
#define Crad_h
class Crad {
public:
	void setRed(int);
	void setBlue(int);
	void setBlack(int);
	void setOrange(int);
	void setNumber(int);
	void setJoke(int);
	int getRed()const;
	int getBlue()const;
	int getBlack()const;
	int getOrange()const;
	int getNumber()const;
	int getJoke()const;
private:
	int red;
	int blue;
	int black;
	int orange;
	int number_arr[13];
	int joke_arr[2];

};
#endif