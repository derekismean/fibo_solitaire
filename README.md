# fibo_solitaire

This project was done in my System Programming course. It is a console-based solitaire game in C++ which uses Fibonacci sequence numbers. A user is given a deck of 52 cards, which
can be shuffled or displayed. 

When the game is played, piles are made based on the sum of the numbers of the cards in the deck. One by one, a card's value is added to the sum and the next card is evaluated. 
Once the sum becomes a number in the Fibonacci sequence, a new pile is started.

The game ends when every card in the deck has been evaluated. The game is won if the sum of the last pile is a Fibonacci number. It the last pile's sum is not a Fibonacci number,
the game is lost.
