#include "includes/includes.h"

void playMastermind(const int size, const int letters, const char start, const char end) {
    
    cout    << "Guess the letters & their position in a randomly generated text string between: " << start << " & " << end << endl
            << "Your input must be " << size << " characters." << endl;

    string code = randomizeString(size, start, end);
    string guess = "";
    int correct = 0;
    int correctPosition = 0;
    unsigned int tries = 10;

    do {
        if(tries == 0) {
            cout << "You failed, you are certainly not a mastermind." << endl;
            return;
        }
            
        cout << "You have " << tries << " left to get it right." << endl;

        guess = readInputToString(start, end, size);
        correct = checkCharacters(code, guess);
        correctPosition = checkCharactersAndPosition(code, guess);

        cout    << "You had " << correct << " letters at any order." << endl
                << "You had " << correctPosition << " letters at the correct position." << endl;
        
        // ---------------------// The correct code //------------------------- //
        //cout    << code << endl;
        // -------------------------------------------------------------------- //
        
        tries--;
    }
    while (correctPosition != size);
    cout << "Congratulations, you are officially a mastermind! You guessed correct!" << endl;
}

void playMastermindGFX(const int size, const int letters, const char start, const char end) {
    
    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};

    cout    << "Guess the letters & their position in a randomly generated text string between: " << start << " & " << end << endl
            << "Your input must be " << size << " characters." << endl
            << "The color scheme: " << endl << "A = Red, B = Green, C = Yellow, D = Blue, E = Pink" << endl;

    string code = randomizeString(size, start, end);
    string guess = "";
    int correct = 0;
    int correctPosition = 0;
    unsigned int tries = 10;
    
    addGuess(mwin, code, code.length(), code[0], 0);
    hideCode(mwin, code.length());
    mwin.redraw();

    do {
        if(tries == 0) {
            cout << "You failed, you are certainly not a mastermind." << endl;
            return;
        }
            
        cout << "You have " << tries << " left to get it right." << endl;

        guess = mwin.getInput(size, start, end);
        correct = checkCharacters(code, guess);
        correctPosition = checkCharactersAndPosition(code, guess);

        cout << "Your guess: " << guess << endl;

        addGuess(mwin, guess, code.length(), 'A', 11 - tries);
        addFeedback(mwin, checkCharactersAndPosition(code, guess), checkCharacters(code, guess), code.length(), 11 - tries);
        mwin.redraw();


        cout    << "You had " << correct << " letters at any order." << endl
                << "You had " << correctPosition << " letters at the correct position." << endl;
        
        // ---------------------// The correct code //------------------------- //
        cout    << code << endl;
        // -------------------------------------------------------------------- //
        
        tries--;
    }
    while (correctPosition != size);
    cout << "Congratulations, you are officially a mastermind! You guessed correct!" << endl;
}




int checkCharactersAndPosition(string code, string guess) {

    unsigned int a = 0;

    for(unsigned int i = 0; i < code.size(); i++) {
        if (code[i] == guess[i])
            a++;
    }

    return a;
}


int checkCharacters(string code, string guess) {

    string temp = guess;
    unsigned int a = 0;

    for(char c : code) {
        // Checks if character "c" exists in "temp". <-- string::npos indicates that there was none found.
        if(temp.find(c) != string::npos) {
            // erase at "index, character to erase".
            temp.erase(temp.find(c), 1);
            a++;
        }
    }
    return a;
}