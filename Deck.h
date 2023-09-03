// Derek Mean
// CECS 325-01
// Prog - Fibonacci Solitaire 
// 2/13/23
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
private:
        Card deck[52];
        int count;
	char rank_list[13];
	char suit_list[4];
public:
        Deck();
	void resetDeck();
	Card deal();
	void shuffle();
	bool isEmpty();
        void show();
};

#endif
