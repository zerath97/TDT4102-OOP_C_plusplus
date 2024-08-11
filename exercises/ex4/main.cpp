#include "includes/includes.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	// Oppgave 1
	{
	// 1c
	testCallByValue();
	
	// 1d
	testCallByReference();

	// 1e)
	int firstNum = 2;
	int secondNum = 3;
	
	// Using pair to make the syntax for the values easier to read.
	pair<int, int> swappedNumbers = swapNumbers(firstNum, secondNum);
	cout << "First number: " << swappedNumbers.first << " , Second number: " << swappedNumbers.second << endl;

	// Changes the values of "firstNum" and "secondNum" defined above.
	swapNumbersByRef(firstNum, secondNum);
	cout << "First number: " << firstNum << " , Second number: " << secondNum << endl;

	// Får ikke swapNumbersByConstRef til å funke, tror det er meningen.
	}

	// Oppgave 2d
	{
		Student student1;
		student1.name = "Sindre";
		student1.studyProgram = "Elsys";
		student1.age = 24;

		printStudent(student1);
		
		cout << isInProgram(student1, "Elssys") << endl;



	}

	// Oppgave 3
	{
		cout << randomizeString(5, 'G', 'T') << endl;
		testString();
		cout << endl;

		// // f
		// cout << readInputToString('A', 'K', 5) << endl;
		
		// //g
		// cout << "Amount of the specified character: " << countChar("hello", 'l') << endl;
		
	}

	constexpr int size = 4;
	constexpr int letters = 6;
	const char start = 'A';
	const char end = 'A' + (letters - 1);

	// Oppgave 4
	{
		
		//playMastermind(size, letters, start, end);


	}

	// Oppgave 5
	{

		playMastermindGFX(size, letters, start, end);

		
	}


	keep_window_open();
}

//------------------------------------------------------------------------------
