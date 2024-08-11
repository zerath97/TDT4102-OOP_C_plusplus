#include "includes.h"

// Overwrites file on opening and writes words & newline till "quit" is entered.
void writeWordToFile(const string& fileName);

// Appends to a file and writes words & newline till "quit" is entered.
void appendWordToFile(const string& fileName);



// Reads each line and add the line to a string vector.
void readLineFromFile(const string& fileName, vector<string>& text);

// Reads text from file and duplicate it to another file, but with linenumbers equals first letter in each line.
void readAndWriteFile(const string& fileName);

// Returns a map that acts as a counter for each letter used in a file.
map<char, int> countCharsInFile(const string& fileName);