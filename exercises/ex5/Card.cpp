#include "includes.h"


// ------------------------------- // Class: Card // ------------------------------- //

Card::Card(Suit suit, Rank rank) : s(suit), r(rank) {
}

Suit Card::getSuit() {
    return s;
}

Rank Card::getRank() {
    return r;
}

string Card::toString() {
    return rankToString(r) + " of " + suitToString(s);
}

string Card::toStringShort() {
    string suit = "";
    suit += suitToString(s).at(0);
    return suit + to_string(static_cast<int>(r));
}

// ------------------------------- //   End   // ------------------------------- //




// ------------------------------- // Functions // ------------------------------- //

string suitToString(Suit suit) {
    return mapSuitToString.at(suit);
}

string rankToString(Rank rank) {
    return mapRankToString.at(rank);
}

// ------------------------------- //    End    // ------------------------------- //