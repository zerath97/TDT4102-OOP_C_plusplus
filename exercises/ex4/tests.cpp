#include "includes/includes.h"

void testCallByValue() {

    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);

    cout    << "v0: "           << v0
            << " increment: "   << increment
            << " result: "      << result
            << endl;
}

void testCallByReference() {

    int v0 = 5;
    int startValueRef = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(startValueRef, increment, iterations);

    cout    << "v0: "           << v0
            << " increment: "   << increment
            << " result: "      << startValueRef
            << endl;
}


void testString() {

    string grades = randomizeString(8 ,'A', 'F');
    
    cout << "------------" << endl;

    // Used for the iteration over the list of grades. Grade: A = 5, B = 4...
    unsigned int i = 5;
    unsigned int sum = 0;

    
    for(pair<char, int> Map : countGrades(grades)){
        // .first gets the key information, while .second gets the value of the respective key.
        cout << Map.first << " : " << Map.second << endl;

        // Sets the key of the map to the number equivelant of the grade.
        Map.first = i;
        sum += Map.first * Map.second;
        i--;
    }

    // Calculating the average grade from the map.
    double averageGrade = static_cast<double>(sum) / static_cast<double>(grades.length());

    cout    << "------------" << endl
            << "Average grade: "
            << averageGrade << endl
            << "------------" << endl;

    cout << "Grades: ";
    for(unsigned int i = 0; i < grades.length(); i++)
        cout << grades[i] << " ";

}

