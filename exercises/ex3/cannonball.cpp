#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

double acclY() {
    return (-9.81);
}

double velY(double initVelocityY, double time) {
    return initVelocityY + acclY()*time;
}

double posX(double initPosX, double initVelX, double time) {
    return initPosX + (initVelX * time); // no acceleration in x-axis
}

double posY(double initPosY, double initVelY, double time) {
    return initPosY + (initVelY * time) + ((acclY() * pow(time, 2))/2);
}

void printTime(double time) {
    int h = time / 3600;
    int m = (time - h*3600) / 60;
    int s = time - h*3600 - m*60;
    cout << "Time used: " << h << ":";
    if(m < 10)
        cout << "0" << to_string(m) << ":";
    else
        cout << m << ":";
    if(s < 10)
        cout << "0" << to_string(s);
    else
        cout << s;

}

double flightTime(double initVelocityY) {
    return (-2*initVelocityY)/(acclY());
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    cout << "Comparing: " << name << " with " << toOperand << ":" << endl;
    if(abs(compareOperand - toOperand) >= maxError) // absolute value to make sure we compare only positive numbers.
        cout << "Your numbers are not equal." << endl;
    else
        cout << "Your numbers are approximately equal." << endl;
}

// Using absolute value to make sure we 
double getVelocityX(double theta, double absVelocity) {
    return abs(absVelocity) * cos(theta);
}

double getVelocityY(double theta, double absVelocity) {
    return abs(absVelocity) * sin(theta);
}

vector<double> getVelocityVector(double theta, double absVelocity) {
    return { getVelocityX(theta, absVelocity), getVelocityY(theta, absVelocity) };
}

double getDistanceTraveled(double velocityX, double velocityY) {
    return posX(0, velocityX, flightTime(velocityY));
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    return getDistanceTraveled(velocityX, velocityY) - distanceToTarget;
}

void playTargetPractice() {
    double theta = 0;
    double absVelocity = 0;
    int targetDistance = randomWithLimits(100, 1000);
    
    cout << "----------------------------------------------" << endl;
    cout << "Target practice" << endl;
    // User has 10 life, so 10 chances to hit the target.
    for(int life = 10; life >= 0; life--) {
        cout << "----------------------------------------------" << endl;
        cout << "Enter the angle to shoot at: "; cin >> theta;
        cout << "Enter the absVelocity at start: "; cin >> absVelocity;
        cout << "----------------------------------------------" << endl;
        double distanceFromTarget = targetPractice(targetDistance, getVelocityX(theta, absVelocity), getVelocityY(theta, absVelocity));

        cout << "Fire in the hole!" << endl;
        cout << "... ... ... ... " << endl;;
        cout << "----------------------------------------------" << endl;
        cout << "Your distance to the target was " << abs(distanceFromTarget) << "m" << endl;
        printTime(flightTime(getVelocityY(theta, absVelocity)));
        cout << " to get there." << endl;
        cout << "----------------------------------------------" << endl;
        if(abs(distanceFromTarget) < 5){
            cout << "Congratulations! Your shot was close enough to cause a destructions beyond repair to the target." << endl;
            cout << "----------------------------------------------" << endl;
            break;
        }
        else {
            string deviantFromTarget = "";
            life--;

            if(distanceFromTarget > 0)
                deviantFromTarget = " You shot too far! ";
            else
                deviantFromTarget = " You did not shoot far enough! ";

            if(life == 0)
                cout << "GAME OVER! You have missed all your shots." << " By the way," << deviantFromTarget << endl;
            else        
                cout << "Missed target!" << deviantFromTarget << "You now have " << life << " lives left. Try again!" << endl;
        }
        cout << "----------------------------------------------" << endl;
    }
    string retry = "";
    cout << "Do you want to play again? (Y/N)" << endl;
    cin >> retry;
    if(retry == "Y" || "y")
        playTargetPractice();
}
