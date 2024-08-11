#include "includes.h"


class CardDeck {
    private:
        vector<Card> cards;
        
        // Swaps the suit and rank (as integers) from the innate position (iPos) to the changed position (cPos).
        void swap(int iPos, int cPos);
        

    public:
        CardDeck();
        void print();
        void printShort();
        // Shuffles the card randomly.
        void shuffle();
        // Draws the last card of the deck and removes it from the deck.
        Card drawCard();
        

};