// Derek Mean
// CECS 325-01
// Prog 1 - Fibonacci Solitaire
// 2/13/23
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <string>
using namespace std;


// Fibo function
int fibo(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return fibo(n-1) + fibo(n-2); // recursion
}

// Determine if Sum is a Fibonacci Number
bool isFibo(int sum)
{
	int fibo_list[20];

	for (int index = 0; index < 20; index++)
	{
		// Use fibo() funct. to store fibo numbers from 1-20
		// Store in fibo_list[] array
		fibo_list[index] = fibo(index + 1);
	}	
	
	// Check if the sum is a Fibonacci number
	for (int k = 0; k < 20; k++)
	{
		// Iterate through list, check if the sum equals a fibo number
		if (sum == fibo_list[k])
			return true;
	}
	return false;

}

// Play Fibo Solitaire
bool playFibo(Deck d1)
{
	cout << "\nPlaying Fibonacci Solitaire!!!" << endl;
        cout << endl;

	// Initialize variables for keeping track of certain values
        int num_piles = 1;
        int curr_sum = 0;
        int prev_sum;
        int card_val;

        while (d1.isEmpty() == false)
        {
		// Deal card, obtain value, & add to current sum
        	Card dealt_card = d1.deal();

                card_val = dealt_card.getValue();
                curr_sum += card_val;

                dealt_card.show();
                cout << ", ";

		// Store sum for later use
                prev_sum = curr_sum;

                if (isFibo(curr_sum) == true)
                {
			// If sum is a Fibo num, increment piles, output sum,
			// and reset the current sum to 0
                	num_piles += 1;
                        cout << "Fibo:" << curr_sum << endl;
                        curr_sum = 0;
                }
	}

       	string result;

	// If the last pile sum is a Fibo number, the user wins
        if (isFibo(prev_sum) == true)
        	result = "Winner";
        else
        {
	// If not, the user loses
        	cout << "Last Pile NOT Fibo:" << curr_sum << endl;
                result = "Loser";
        }
        
	// Output result and pile count
	cout << "\n" << result << " in " << num_piles << " piles!\n";
		
	// Function returns true if user wins, false if user loses
	if (result == "Winner")
		return true;
	return false;
	
}


// Main 
int main() 
{
	Deck myDeck;

	cout << "\nWelcome to Fibonacci Solitaire!" << endl;
  
	int user_choice = 0;
  
	// Continue to display menu until user quits
	while (user_choice != 6) 
	{

	cout << "1) Create New Deck\n2) Shuffle Deck\n3) Display Deck\n4) Play Fibo Solitaire\n5) Win Fibo Solitaire\n6) Exit" << endl;
    
	cin >> user_choice;
	
	// 1. Create New Deck
	if (user_choice == 1)
	{
		myDeck.resetDeck();
		cout << "\nNew Deck Created." << endl;
	}

	// 2. Shuffle Deck
	else if (user_choice == 2)
	{	
		myDeck.shuffle();
		cout << "\nDeck has been shuffled." << endl;
	}

	// 3. Display Deck
	else if (user_choice == 3) 
	{
		cout << "\nCurrent Deck:" << endl;
		myDeck.show();
	}

	// 4. Play Fibo Solitaire
	else if (user_choice == 4) 
	{
		playFibo(myDeck);
	}

	// 5. Win Fibo Solitaire
	else if (user_choice == 5) 
	{
		int games_played = 1;
		myDeck.resetDeck();
		myDeck.shuffle();
		bool play_game = playFibo(myDeck);
		
		// Continue to play Fibo Solitaire until the user wins
		while (play_game == false)
		{
			myDeck.shuffle();
			play_game = playFibo(myDeck);
			games_played += 1;
			cout << endl;
		}
		// Output the number of games it took until a winning game
		cout << "\nGames Played: " << games_played << endl;
	}

	cout << "\n";

	}
  
}
