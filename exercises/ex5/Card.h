#include "std_lib_facilities.h"

// ------------------------------- // Enums // ------------------------------- //

// The suit of a card can have.
enum class Suit{ clubs = 1, diamonds, hearts, spades};

// The ranks a card can have.
enum class Rank{ two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

enum class BJRank{aceLow = 1, two, three, four, five, six, seven, eight, nine, ten, jack = 10, queen = 10, king = 10, aceHigh = 11};

// ------------------------------- //  End  // ------------------------------- //

// Suits of cards as a string.
const map<Suit, string> mapSuitToString = {{Suit::clubs, "Clubs" }, {Suit::diamonds, "Diamonds" }, {Suit::hearts, "Hearths" }, {Suit::spades, "Spades" }};

// Rank of cards as a string.
const map<Rank, string> mapRankToString =   {   {Rank::two, "Two" }, {Rank::three, "Three" }, {Rank::four, "Four" }, {Rank::five, "Five" }, {Rank::six, "Six" }, 
                                                {Rank::seven, "Seven" }, {Rank::eight, "Eight" }, {Rank::nine, "Nine" }, {Rank::ten, "Ten" }, {Rank::jack, "Jack" }, 
                                                {Rank::queen, "Queen" }, {Rank::king, "King" }, {Rank::ace, "Ace" }        
                                            };



// ------------------------------- // Classes // ------------------------------- //

class Card {
    private:
        Suit s;
        Rank r;

    public:
        Card(Suit suit, Rank rank);
        Suit getSuit();
        Rank getRank();
        // Format: "Rank" of "Suit".
        string toString();
        // Format: Suit(first letter) Rank(integer value).
        string toStringShort();
};

// ------------------------------- //   End   // ------------------------------- //



// ------------------------------- // Functions // ------------------------------- //

// Returns the suit as a string value.
string suitToString(Suit suit);

// Returns the rank as a string value.
string rankToString(Rank rank);

// ------------------------------- //    End    // ------------------------------- //