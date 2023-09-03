// Derek Mean
// CECS 325-01
// Prog - Fibonacci Solitaire 
// 2/13/23
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "Deck.h"
#include <iostream>
#include <ctime>
using namespace std;

Deck::Deck()
{
	count = 52;

	// Create arrays with ranks & suits
	int rank_list[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	int suit_list[4] = {'S', 'H', 'D', 'C'};
	
	// Create all 52 cards and store in deck array
	int curr_rank = 0;
	int curr_suit = 0;
	for (int k = 0; k < count; k++)
	{
		Card c;
		c.setCard(rank_list[curr_rank], suit_list[curr_suit]);
		deck[k] = c;
		curr_rank += 1;
		if (curr_rank == 13)
		{	
		curr_suit += 1;
		curr_rank = 0;
		}
	}

}

void Deck::resetDeck()
{
	// Reset deck to look like a new, unshuffled deck
	count = 52;
	int rank_list[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        int suit_list[4] = {'S', 'H', 'D', 'C'};


        int curr_rank = 0;
        int curr_suit = 0;
        for (int k = 0; k < count; k++)
        {
                Card c;
                c.setCard(rank_list[curr_rank], suit_list[curr_suit]);
                deck[k] = c;
                curr_rank += 1;
                if (curr_rank == 13)
                {
                curr_suit += 1;
                curr_rank = 0;
                }
        }


}

Card Deck::deal()
{
	// Return the top card of the deck
	Card curr_top_card = deck[0];
	Card empty_card;

	// Set new top card
	for (int n = 0; n < 52; n++)
	{
		// Shift every card to the left in the deck
		deck[n] = deck[n + 1];
	}
	
	deck[51] = empty_card;
	// Reduce count by 1
	count -= 1;
	return (curr_top_card);
}

void Deck::shuffle()
{
	// Set rand() seed to time at 0
	srand(time(0));
	
	int rand_num_1;
	int rand_num_2;
	// Use temporary Card variable to store
	Card temp;
	
	for (int swap = 0; swap < 500; swap++)
	{
		// Generates 2 rand int's from 0-the current count
		rand_num_1 = rand() % count;
		rand_num_2 = rand() % count;
		
		temp = deck[rand_num_1];
		deck[rand_num_1] = deck[rand_num_2];
		deck[rand_num_2] = temp;
	}

}

bool Deck::isEmpty()
{
	// Deck is empty once count reaches 0,
	// meaning every card has been dealt
	if (count == 0)
		return true;
	return false;
	
}

void Deck::show()
{
	// Show every card in the current deck
	for (int i = 0; i < count; i++)
	{
		deck[i].show();
		cout << " ";
		// Every 13 cards, start a new line (4 rows, 13 columns)
		if ((i + 1) % 13 == 0)
		{
		cout << endl;
		}
	}
}


