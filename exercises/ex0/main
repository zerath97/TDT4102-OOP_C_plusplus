//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'

// Finner det største heltallet av to verdier.
int maxOfTwo(int a, int b) {

	if (a > b)
	{
		/* code */
		cout << "A is greater than B" << endl;
		return a;
	}
	else
	{
		cout << "B is greater than or equal to A" << endl;
		return b;
	}

}

// Skriver ut de "n"-te første fibonaccitallene.
int fibonacci(int n) {
	int a = 0;
	int b = 1;
	
	cout << "Fibonacci numbers: " << endl;
	for (int x = 1; x < n + 1; x++)
	{
		/* code */
		cout << x << " -- " << b << endl;
		int temp = b;
		b += a;
		a = temp;
	}

	cout << "----" << endl;
	return b;
}

// Summerer kvadrert tall opp til og med "n".
int squareNumberSum(int n) {

	int totalSum = 0;
	for (int i = 0; i <= n; i++) {
		totalSum += i * i;
		cout << (i * i) << endl;
	}
	cout << "----" << endl;
	cout << "Totalsum: " << endl;
	return totalSum;

}

// Trekanttall
void triangleNumbersBelow(int n) {

	int acc = 1;
	int num = 2;
	int i = 0;

	cout << "Triangle numbers below " << n << ":" << endl;

	while(acc < n) {
		if (i == 0) {
			cout << acc;
			i++;
		}
		else {
			cout << " -- " << acc;
		}
		acc += num;
		num += 1;
	}
	cout << endl;
}

// Primtall 1
bool isPrime(int n) {

	for(int j = 2; j < n; j++) {

		if( (n % j) == 0 ) {
			return false;
		}

	}
	return true;
}
// Primtall 2
void naivePrimeNumberSearch(int n) {

	for(int number = 2; number < n; number++) {

		if(isPrime(number)){
			cout << number << " is a prime" << endl;
		}
	}

}

// Største nevner mindre enn tallet selv
int findGreatestDivisor(int n) {
	int divisor_value = 0;
	for(int divisor = n-1; divisor > 0; divisor--) {

		if( (n % divisor) == 0) {
			divisor_value = divisor;
		}
	}
	return divisor_value;
}



// C++ programs start by executing the function main
int main()
{
	// Største av to heltall
	cout << "Oppgave a)" << endl;
	cout << maxOfTwo(5,6) << endl;

	// Fibonacci-rekker
	cout << "Oppgave c)" << endl;
	cout << fibonacci(5) << endl;

	// Sum av kvadrerte heltall
	cout << "Oppgave d)" << endl;
	cout << squareNumberSum(5) << endl;

	// Trekanttall
	cout << "Oppgave e)" << endl;
	triangleNumbersBelow(15);

	// Primtmall 1
	cout << "Oppgave f)" << endl;
	cout << isPrime(5) << endl;
	cout << endl;

	// Primtall 2
	cout << "Oppgave g)" << endl;
	naivePrimeNumberSearch(7);
	cout << endl;

	// Største nevner mindre enn tallet selv
	cout << "Oppgave h)" << endl;
	cout << findGreatestDivisor(5) << endl;

	keep_window_open();
}

//------------------------------------------------------------------------------
