
// a)
double discriminant(double a, double b, double c) {
    return (b*b) - (4*a*c);
}


// b)
// a, b, c <-- 2. equation
void printRealRoots(double a, double b, double c) {
    
    double x[2];
    if(discriminant(a, b, c) > 0) {
        x[0] = (-b + sqrt(discriminant(a, b, c))) / (2 * a);
        x[1] = (-b - sqrt(discriminant(a, b, c))) / (2 * a);
        cout << "\t x_1 = " << x[0] << "\t x_2 = " << x[1] << endl;
    }
    else if(discriminant(a, b, c) == 0) {
        cout << "x = 0" << endl;
    }
    else {
        cout << "No solutions (reason: negative discriminant)." << endl;
    } 


}
// c)
// Lets user input values of a, b and c for the quadratic equation, to have it solved.
void solveQuadraticEquation() {
    double a, b, c;
    
    cout << "Enter (a): "; cin >> a;
    cout << "Enter (b): "; cin >> b;
    cout << "Enter (c): "; cin >> c;
    cout << "---------------------------------------" << endl;
	cout << "Your function: " << a << "x^2 + (" << b << ")x + (" << c << ")" << endl << endl;
	cout << "Solutions: ";
    printRealRoots(a, b, c);
}