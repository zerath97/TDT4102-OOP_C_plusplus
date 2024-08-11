
// Skriv hvor mange tall du ønsker å summere, deretter tallene.
int sumIntegers(int numbers) {
	
	int inputDigit = 0;
	int sum = 0;

	for(int i = 0; i < numbers; i++) {
		cout << "Enter a number: ";
		cin >> inputDigit;
		sum += inputDigit;
	}

 	return sum;
}

// Summerer verdier du taster inn til "0" blir gitt, da vises summen på skjermen.
int sumWhileNotZero() {

	int number = 0;
	int sum = 0;

	do
	{
		cout << "Enter a number: ";
		cin >> number;

		sum += number;

	} while (number != 0);
	
	return sum;

}

// Leser og returnerer et desimaltall.
double inputDouble() {
	double num = 0;

	cout << "Write a decimalnumber: ";
	cin >> num;
	return num;
}

// Konverterer NOK til Euro
double convertNOKToEuro(){
	
	double NOK = 0;
	double EuroValue = 9.90;
	
	cout << "Convert NOK to Euro" << endl;
	cout << "-----------------------------" << endl;
	cout << "Amount of NOK: ";
	cin >> NOK;

	return (NOK / EuroValue);

}

// Makes a 2D table of the multiplaction table where the heigh and width can be chosen at will.
void multiplyTable(int height, int width) {
	if(width > 35) {
		width = 35;
		cout << "Too long! Width is set to 35." << endl;
	}
	// Defining a 2D-vector.
	vector<vector<int>> multiplyTable;
	
	// Change the size of the vector at the upper level.
	multiplyTable.resize(height);

	// Upper level is the rows
	for(int y = 0; y < height; y++) {

		// Change the size of the vector at the lower level.
		multiplyTable[y].resize(width);
		cout << setw(6);
		// Lower level is the columns
		for(int x = 0; x < width; x++) {
			// Multiplies the "row integer" with the "column integer".
			multiplyTable[y][x] = (x + 1) * (y + 1);
			cout << multiplyTable[y][x] << setw(6);
		}
		cout << endl;
	}
} 