
// Summerer to tall.
int add(int a, int b) {

	return a + b;

}

void inputIntegersAndPrintProduct()
{

	int x = 0;
	int y = 0;

	cout << "Write two integers: ";
	cin >> x;
	cin >> y;

	int product = x * y;
	cout << x << " * " << y << " = " << product << endl;
}

// // Lar deg skrive inn et heltall og viser deg det du skrev.
void inputAndPrintInteger()
{

	int x = 0;

	cout << "Write an integer: ";
	cin >> x;
	cout << "----------" << endl;
	cout << "You wrote: " << x << endl;
}

// Lar brukeren skrive inn et heltall og returnerer den.
int inputInteger() {

	int number{0};

	cout << "Write an integer: ";
	cin >> number;
	return number;
}

// Summerer to heltall brukeren taster inn.
void inputIntegersAndPrintSum() {

	int a {inputInteger()};
	int b {inputInteger()};

	int sum = a + b;

	cout << "Sum of the numbers: " << sum << endl;
}

// Sjekker om brukerinput er oddetall eller partall.
bool isOdd(int number) {

	if(number % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}

// Skriver ut antall sekunder på formatet: "h time(r), m minutt(er), s sekund(er)".
void printHumanReadableTime(int seconds) {

	
	int h = seconds / 3600;
	int min = (seconds - (h * 3600)) / 60;
	int sec = seconds - (h * 3600) - (min * 60);

	string hour{""};
	string minute{""};
	string second{""};

	if(h == 1) {
		hour = " hour, ";
	}
	else {
		hour = " hours, ";
	}
	if(min == 1) {
		minute = " minute, and "; 
	}
	else {
		minute = " minutes, and ";
	}
	if (sec == 1) {
		second = " second";
	}
	else {
		second = " seconds";
	}

	cout << h << hour << min << minute << sec << second << endl; 
} 