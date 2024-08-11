

// a)
void menu(){
    int choice = 0;
	do
	{
		// The chosen function. Using double because here we have functions of both "int" and "double" type.
		double func = 0;

		cout << "Choose function:" << endl;
		cout << "0) ||>  Exit" << endl;
		cout << "1) ||>  Sum two numbers" << endl;
		cout << "2) ||>  Sum multiple numbers" << endl;
		cout << "3) ||>  Convert NOK to EURO" << endl;
        // 3b) - Multiplication table
		cout << "4) ||>  Multiplication table, you decide size" << endl;
		// 4d) Solve quadratic equation
		cout << "5) ||>  Solve quadratic equation, choose: a, b & c." << endl;
		cout << "---------------------------------------" << endl;
		cout << "Chose a number (0 - 6): ";
		cin >> choice;
		cout << "---------------------------------------" << endl;

		if(choice == 1) {
			func = sumIntegers(2);
			cout << "---------------------------------------" << endl;
			cout << "= " << func << endl;
		}
		else if(choice == 2) {
			int numbers = 0;
			cout << "Numbers to add together: ";
			cin >> numbers;
			func = sumIntegers(numbers);
			cout << "---------------------------------------" << endl;
			cout << "= " << func << endl;
		}
		else if(choice == 3) {
			func = convertNOKToEuro();
			cout << "---------------------------------------" << endl;
			cout << "You got a value of " << func << " Euro in NOK." << endl;			
		}
        // 3b) - Multiplication table
		else if(choice == 4) {
			int height = 0;
			int width = 0;
			cout << "Height: ";
			cin >> height;
			cout << "Width: ";
			cin >> width;
			multiplyTable(height, width);
		}
		// 4d) - Quadratic Equation
		else if(choice == 5) {
			solveQuadraticEquation();
		}
		else if(choice == 6) {
			printBalanceByYear();
		}
		
		cout << "---------------------------------------" << endl;		
	} while(choice != 0);
}