#include<vector>
#ifndef Card_h
#define Card_h

class Card 
{
public:
	vector<double>TotalCard;
	int number;
	int color;
	int joker;
private:
	Card();
	Card(int, int, int);
	void getCard();
	void getNumber(int);
	void getColor(int);
	void getJoker(int);
};
#endif


Card::Card()
{

}

Card::Card(int number, int color, int joker)
{

}

void Card::getCard()
{
	 for (int a = 1; a <= 2; a++) 
	 {
		 for (int i = 1; i <= 13; i++)
		 {
			 for (int j = 1; j <= 4; j += 1)
			 {
				 TotalCard.push_back(i + 0.1 * j);
			 }
		 }
	 }
	TotalCard.push_back(10,10);
}


 inline void Card::getNumber(int n)
 {
	 number = n;
 }


 inline void Card::getColor(int c)
 {
	 color = c;
 }

 
 inline void Card::getJoker(int j)
 {
	 joker = j;
 }
