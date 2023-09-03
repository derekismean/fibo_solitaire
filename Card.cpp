// Derek Mean
// CECS 325-01
// Prog - Fibonacci Solitaire 
// 2/13/23
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "Card.h"
using namespace std;

Card::Card()
{
	r = 'e'; // Default card's rank and suit
	s = 'e';
	value = 0;
}

Card::Card(char rank, char suit)
{
	r = rank;
	s = suit;
}

void Card::setCard(char rank, char suit)
{
	r = rank;
	s = suit;
}

int Card::getValue()
{
	// Value of ace card: 1
	if (r == 'A') 
	{
	value = 1;
	}
	// If card rank is between 2-9, return its rank as the value
	else if (1 <= int(r) - 48 && int(r) - 48 <= 9) 
	{
	value = int(r) - 48;
	}
	// Cards of ranks 10, Jack, Queen, & King have values of 10
	else if (r == 'T' || r == 'J' ||  r == 'Q' || r == 'K')
	{
	value = 10;
	}

	return(value);
}

void Card::show()
{
	// Display 10 in numeric form
	if (r == 'T') 
	{
	cout << "10" << s;
	}
	// Display the rank and suit together
	else
	{
	cout << r << s;
	}
}
