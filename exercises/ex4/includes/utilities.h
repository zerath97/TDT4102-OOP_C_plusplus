
struct Student {
    string name;
    string studyProgram;
    int age;
};


// Adds the "increment" to "startValue" by the amount of times stated as "numTimes".
int incrementByValueNumTimes(int startValue, int increment, int numTimes);

// Adds "increment" to "startValue" and change it "numTimes" amount of times.
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

// Swaps two integers, so the first becomes second and vice versa.
pair<int, int> swapNumbers(int first_Int, int second_Int);
// Swaps two integers, so the first becomes second and vice versa.
void swapNumbersByRef(int& first_Int, int& second_Int);
// Swaps two integers, so the first becomes second and vice versa.
void swapNumbersByConstRef(const int& first_Int, const int& second_Int);

// Prints information about the student.
void printStudent(Student student);

// Checks if the student studies at the study program that is entered.
bool isInProgram(Student student, string studyProgram);


// Randomizes the a string based on character interval given in parameters.
string randomizeString(unsigned int lengthString, char start, char end);

// Writes the user input to screen if it is within the parameters lsited.
string readInputToString(char start, char end, unsigned int lengthString);

// Returns the amount of characters in "text".
int countChar(string text, char c);

// Adds a map of the key: "grade character" & value: "amount of the keys in the string "grades"".
map<char, int> countGrades(string grades);