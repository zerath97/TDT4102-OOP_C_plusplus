#include "includes/includes.h"


int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for(int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for(int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}


pair<int, int> swapNumbers(int first_Int, int second_Int) {
    return {second_Int, first_Int};
}

void swapNumbersByRef(int& first_Int, int& second_Int) {
    const int temp = first_Int;
    first_Int = second_Int;
    second_Int = temp;
}


// Doesn't allow to change the parameters, because they are initiated as constants.
// void swapNumbersByConstRef(const int& first_Int, const int& second_Int) {
//     int temp = first_Int;
//     first_Int = second_Int;
//     second_Int = temp;
// }


void printStudent(Student student) {
    cout    << "Studentinformation:" << endl
            << "------------------------------" << endl
            << "Name: \t" <<   student.name << endl
            << "Study program: \t" << student.studyProgram << endl
            << "Age: \t" << student.age << endl;
    return;
}

bool isInProgram(Student student, string studyProgram) {
    return student.studyProgram == studyProgram;
}

string randomizeString(unsigned int lengthString, char start, char end) {
    string word;;
    char randChar;

    srand(static_cast<unsigned int>(time(nullptr)));

    for(unsigned int i = 0; i < lengthString; i++) {
        randChar = start + rand() % ((end + 1) - start);
        word += randChar;
    }
    return word;
}

string readInputToString(char start, char end, unsigned int lengthString) {
    
    // Sets characters to their lower version, E.g: 'A' -> 'a', so it becomes more intuitive to do comparisons.
    start = toupper(start);
    end = toupper(end);
    string text = "";
    
    cout    << "------------------------------------"
            << endl
            << "Enter a string: ";
    cin     >> text;
    
    // Checks each character in the string to see if it is valid.
    for(unsigned int i = 0; i < text.length(); i++) {

        text[i] = toupper(text[i]);

        // Checks if each character in the inputted string is within the desired intervals and if it is an alphabetic letter.
        if ( !isalpha(text[i]) || start > text[i] || text[i] > end || text.length() != lengthString )
            // User has to input a new string.
            return readInputToString(start, end, lengthString);
    }
    // Everything went smoothly and the userinput will be returned.
    return text;
}

int countChar(string text, char c) {

    int i = 0;

    for(char l : text)
        if(tolower(l) == tolower(c))
            i++;

    return i;
}

map<char, int> countGrades(string grades) {
    
    map<char, int> gradeCount;
    for(char c = 'A'; c <= 'F'; c++)
        gradeCount[c] = 0;

    for(char l : grades)
        gradeCount[l]++;

    return gradeCount;
}