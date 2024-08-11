#include "includes.h"


// Players in the game (included the dealer).
map<string, vector<Card>> Players();

// Turns the cards a player has into their values in the blackjack game.
int HandValue(vector<Card> hand);

// Starts a game of blackjack.
void Blackjack();