#include "includes.h"

CardDeck::CardDeck() {
    Suit suit;
    Rank rank;

    for(unsigned int s = 1; s <= 4; s++) {
        
        suit = static_cast<Suit>(s);

        for(unsigned int r = 2; r <= 14; r++) {

            rank = static_cast<Rank>(r);
            cards.push_back(Card{suit, rank});
        }
    }
}

void CardDeck::swap(int iPos, int cPos) {
    Card temp = cards.at(iPos);
    cards.at(iPos) = cards.at(cPos);
    cards.at(cPos) = temp;
}

void CardDeck::print() {
    cout << "-------------// All cards in a deck //----------------" << endl;
    for(Card c : cards) {
        cout << c.toString() << endl;
    }
    cout << "-------------// End //----------------" << endl;
}

void CardDeck::printShort() {
    cout << "-------------// All cards in a deck //----------------" << endl;
    for(Card c : cards) {
        cout << c.toStringShort() << endl;
    }
    cout << "-------------// End //----------------" << endl;
}


void CardDeck::shuffle() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for(unsigned int i = 0; i < 52; i++) {
        unsigned int randPos = rand() % 52;
        swap(i, randPos);
    }
}

Card CardDeck::drawCard() {
    Card firstCard = cards.back();
    cards.pop_back();
    return firstCard;
}