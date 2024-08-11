#include "includes.h"



map<string, vector<Card>> Players() {
    map<string, vector<Card>> players;
    players["Dealer"];

    // How many players wish to enter the game.
    int p = 0;

    cout << "How many players: ";
    cin >> p;

    // Adds a new key "Player x" to the map.
    for(unsigned int i = 0; i < p; i++) {
        players["Player " + to_string(i+1)];
    }
    return players;
} 

int HandValue(vector<Card> hand) {

    // Current value of the hand of cards.
    int handValue = 0;

    for(Card card : hand) {
        if (card.getRank() == Rank::jack || card.getRank() == Rank::queen || card.getRank() == Rank::king)
            handValue += 10;
        // Since ace can be either 1 or 11, we determine it's value by the best win condition for the card.
        else if(card.getRank() == Rank::ace && handValue <= 10)
            handValue += 11;
        else if(card.getRank() == Rank::ace && handValue > 10)
            handValue += 1;
        // Uses the values we set in the enum class Rank.
        else
            handValue += static_cast<int>(card.getRank());
    }

    return handValue;
}



// Currently it only supports 1 player and 1 dealer.
void Blackjack() {

    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------<<// Game of blackjack \\\\>>---------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;

    // Created a new deck of cards
    CardDeck cd;

    // Players in the game and their current hand of cards.
    map<string, vector<Card>> players;

    // First card of the dealer, which should be visible.
    vector<Card> firstCardOfDealer;

    // Counts the amount of cards each players has drawn.
    unsigned int cardsDrawn = 0;

    // The value for each players hand at the current time.
    map<string, unsigned int> playersHandValue;

    // Before we start a game we shuffle the deck.
    cd.shuffle();


    // Just to innitiate that the user wants to draw cards.
    string keepPlaying = "Y";
    

    while(true)
    {
        if(keepPlaying != "Y" && playersHandValue["Dealer"] >= 17)
            break;

        // Draws two cards to each user at the start of the game.
        if(players.size() == 0) {
            for(unsigned int i = 0; i < 2; i++) {
                players["Dealer"].push_back(cd.drawCard());
                players["Player 1"].push_back(cd.drawCard());
                cardsDrawn++;
            firstCardOfDealer = players["Dealer"];
            // Since we only want the first card, not the second.
            firstCardOfDealer.pop_back();
        }

        
        }
        else {
            // If user wants to keep draw cards.
            if(keepPlaying == "Y") {
                players["Player 1"].push_back(cd.drawCard());
            }
            // Dealer will draw aslong as the hand remains below 17.
            if(playersHandValue["Dealer"] < 17)
                players["Dealer"].push_back(cd.drawCard());
        
            cardsDrawn++;
        }
        
        // Evaluates the value of each players hand of cards.
        for(const auto& p : players)
            playersHandValue[p.first] = HandValue(p.second);

        cout << "Cards for each player: \t\t | \t" << to_string(cardsDrawn) << endl << "\t\t\t\t | " << endl;;
        cout << "Dealer's first card value: \t | \t" << to_string(HandValue(firstCardOfDealer)) << endl << "\t\t\t\t | " << endl;
        cout << "Player 1's current hand value: \t | \t" << to_string(HandValue(players["Player 1"])) << endl << "\t\t\t\t | " << endl;
        cout << "Players hand: \t\t\t | \t";
        for(Card card : players["Player 1"])
            cout << card.toStringShort() << setw(4);
        cout << endl << "------------------------------------------------------------------------------------------------------" << endl;

        //------To view the dealers full hand------
        // cout << "Dealers hand: ";
        // for(Card card : players["Dealer"])
        //     cout << card.toStringShort() << setw(4);
        // cout << endl;
        //-----------------------------------------

        // The game is automatically over if the player or dealer gets 21 or above.
        if(playersHandValue["Player 1"] >= 21 || playersHandValue["Dealer"] >= 21)
            break;

        // Will ask if the player wants to continue to draw cards.
        cout << "Want to draw a new card?" << endl;
        cout << "Type \"Y\" to get a new card. (Write anything else if not): ";
        cin >> keepPlaying;
        cout << "------------------------------------------------------------------------------------------------------" << endl;
        
    }

    // Will give the final verdict if the player or dealer won.
    string results = "";

    
    if(playersHandValue["Player 1"] > playersHandValue["Dealer"] && playersHandValue["Player 1"] <= 21)
        results = "You have won versus the dealer!";
    else if(playersHandValue["Dealer"] > 21)
        results = "You won versus the dealer!";
    else if(playersHandValue["Player 1"] > 21)
        results = "You have lost the game to the dealer, who ended with a score of " + to_string(playersHandValue["Dealer"]);
    else if(playersHandValue["Player 1"] == playersHandValue["Dealer"])
        results = "You and the dealer had the same score of " + to_string(playersHandValue["Dealer"]);
    else if(playersHandValue["Dealer"] > playersHandValue["Player 1"])
        results = "You have lost the game to the dealer, who ended with a score of " + to_string(playersHandValue["Dealer"]);
    else
        results = "Some error occured.";

    cout << results << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;

    // If the player wants a rematch versus the dealer.
    string newGame = "";
    cout << "Would you like to play a new Blackjack game versus the dealer? (Y/N) ";
    cin >> newGame;
    if(newGame == "Y")
        Blackjack();
}
