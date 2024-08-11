
// a)
// Calculates account balance from year to year.
vector<int> calculateBalance(int startBalance, int interestPercentage, int year) {

    vector<int> balance;

    for(int i = 0; i <= year; i++) {
        balance.push_back(startBalance * pow((1 + (static_cast<double>(interestPercentage)/100)), i));
    }

    return balance;
}

// b)
// Prints out the balance to for each year to look like a table.
void printBalanceByYear() {
    int balance, interest, year;
	cout << "Balance of your bank your upcoming years." << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Current balance: "; cin >> balance;
	cout << "Interests: "; cin >> interest;
	cout << "Years to check: "; cin >> year;
	cout << "-------------------------------------------" << endl;
	cout << setw(6) << "Year" << "\t\t" << setw(12) << "Balance" << endl;
	cout << "-------------------------------------------" << endl;

	vector<int> myBalance = calculateBalance(balance, interest, year);
    
	for(unsigned int e = 1; e < myBalance.size(); e++) {

		cout << setw(6) << e << ": \t" << setw(12) <<myBalance[e] << endl; 
	}
	cout << "-------------------------------------------" << endl;
}
