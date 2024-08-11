#pragma once

// Acceleration in the y-axis direction.
double acclY();

// Speed in the y-axis direction.
double velY(double initVelocityY, double time);

// Position in the x-axis at given time.
double posX(double initPosX, double initVelX, double time);

// Position in the y-axis at given time.
double posY(double initPosY, double initVelY, double time);

// Prints the time on the format: "hour, minutes, time".
void printTime(double time);

// Returns the time the object is in the air based on velocity in y-axis direction.
// Flat surface & no air resistance.
double flightTime(double initVelocityY);

// Tests if two variables of type "double" is approximately equal.
void testDeviation(double compareOperand, double toOperand, double maxError, string name);

// Asks user for an angle.
double getUserInputTheta();

// Asks user for absolute velocity.
double getUserInputAbsVelocity();

// Converts from degrees to radians.
double degToRad(double deg);

// Returns velocity in x- and y-direction.
// Parameters: angle & absolute velocity.
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

// Splits the velocity from absVelocity in it's x- and y-direction.
// Parameters: angle & absolute velocity.
vector<double> getVelocityVector(double theta, double absVelocity);

// Distance when traveled when height is 0.
double getDistanceTraveled(double velocityX, double velocityY);

// Deviation between the distance to the target and actual landing of the ball.
double targetPractice(double distanceToTarget, double velocityX, double velocityY);

// Game to hit the target within a 5m deviation.
// Paremeter: angle & starting velocity.
void playTargetPractice();
