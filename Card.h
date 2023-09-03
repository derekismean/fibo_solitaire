// Derek Mean
// CECS 325-01
// Prog - Fibonacci Solitaire 
// 2/13/23
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#ifndef CARD_H
#define CARD_H


// header file Card.h, has attributes and behaviors
class Card 
{
private:
	char r;
	char s;
	int value;
	
public:
	Card();	// constructor 1
	Card(char, char); // constructor 2
	void setCard(char, char);
	int getValue();
	void show();
};

#endif
