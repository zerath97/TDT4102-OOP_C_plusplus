//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	double T = 5.0;
	double initVelX = 50.0;
	double initVelY = 25.0;
	double constexpr maxError = 0.0001;
	double distanceToTarget = 12; // meters

	// Task 3b
	cout << acclY() << endl;
	cout << velY(initVelY, T) << endl;
	cout << posX(0.0, initVelX, T) << endl;
	cout << posY(0.0, initVelY, T) << endl;
	printTime(T);
	cout << flightTime(initVelY) << endl;

	testDeviation(posX(0.0,initVelX,T), 250.0, maxError, "posX(0.0,50.0,5.0)");
	cout << "-----------------------"<< endl;
	testDeviation(250.00009, 250.0, maxError, "posX(0.0,50.0,5.0)");

	// Task 4d
	vector<double> velocityVector = getVelocityVector(45, 10);
	cout << "Velocity in x- and y-direction:" << endl;
	cout << "x: " << velocityVector[0] << ", y: " << velocityVector[1] << endl;
	cout << "---------------------------" << endl;
	cout << "Distance traveled (in x-direction): " << getDistanceTraveled(velocityVector[0], velocityVector[1]) << endl;;
	cout << "---------------------------" << endl;
	cout << "Deviation between the target and your attempt at hitting it: (negative value means before target)" << endl;
	cout << targetPractice(distanceToTarget, velocityVector[0], velocityVector[1]) << "m" << endl;
	

	// Task 5c
	int lowerLimit = 1;
	int upperLimit = 16;
	srand(static_cast<unsigned int>(time(nullptr)));
	cout << "----------------------------------" << endl;
	cout << "Random numbers between (" << lowerLimit << ") and (" << upperLimit << ")" << endl; 
	for(int i = 0; i < 10; i++)
		cout << randomWithLimits(1, 16) << endl;
	cout << "----------------------------------" << endl;

	// Task 5d
	// Starts a game where you want to hit the target with a cannonball.
	playTargetPractice();


	keep_window_open();
}

//------------------------------------------------------------------------------
