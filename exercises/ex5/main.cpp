//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "includes.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	// Card c = { Suit::clubs, Rank::jack };

	// cout << "Suit: " <<suitToString(Suit::clubs) << endl;
	// cout << "Rank: " << rankToString(Rank::jack) << endl;

	// cout << c.toString() << endl;
	// cout << c.toStringShort() << endl;

	// CardDeck cd;

	// cd.print();
	// cd.printShort();

// Making the class functions public for testing:
	// cd.shuffle();
	// cd.print();
	// cout << cd.drawCard().toString() << endl;
	// cd.printShort();

	// Blackjack spillet:
	// Blackjack();

	keep_window_open();
}

//------------------------------------------------------------------------------

// -------------- Teori -----------------
/*

Oppgave 1e)
	-> Fordelen er at ved symboler vil man kunne se hvor og hva den er definert som, mens streng vil ikke gi feilmelding dersom den er stavet feil.
	-> For integers så kan det være vanskelig å huske hva heltallet representerer.
	-> Klasser er også globale dersom du har inkludert headerfilen, slik at det er lett å aksessere, mens strengverdi må defineres i filene du ønsker.

*/
// -------------------------------