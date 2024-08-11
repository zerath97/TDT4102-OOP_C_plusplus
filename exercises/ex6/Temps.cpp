#include "includes.h"

Temps::Temps() {}

vector<vector<double>> Temps::readTemps(const string& fileName){

    vector<vector<double>> temps;
    string line = "";

    ifstream ist( fileName );
    // Creates 2nd ifstream, so it does not interfere with the original input stream "ist".
    ifstream ist2( fileName );
    
    // Adds the temperatures from each line of the file into two decimal variables in a vector "temps".
    while(ist >> max >> min)
        temps.push_back({max, min});

    return temps;

}

double getMin(vector<vector<double>> doubleVector, unsigned int& index) {
    double t_min = doubleVector[0][0];
    index = 0;

    for (unsigned int i = 0; i < doubleVector.size(); i++) {
        if(doubleVector[i][0] < t_min) {
            t_min = doubleVector[i][0];
            index = i;

        }
        if(doubleVector[i][1] < t_min){
            t_min = doubleVector[i][1];
            index = i;
        }
    }
    
    return t_min;
}

double getMax(vector<vector<double>> doubleVector, unsigned int& index) {
    double t_max = doubleVector[0][0];
    index = 0;

    for (unsigned int i = 0; i < doubleVector.size(); i++) {
        if(doubleVector[i][0] > t_max) {
            t_max = doubleVector[i][0];
            index = i;

        }
        if(doubleVector[i][1] > t_max){
            t_max = doubleVector[i][1];
            index = i;
        }
    }
    
    return t_max;
}

void Temps::tempStats(vector<vector<double>> temps){
    unsigned int index = 0;
    
    double maxTemp = getMax(temps, index);
    cout << "The highest temperature was: " << maxTemp << " on day: " << (index+1) << endl;

    double minTemp = getMin(temps, index);
    cout << "The lowest temperature was: " << minTemp <<  " on day: " << (index+1) << endl;
}


istream& operator >> (istream& is, Temps& t) {
    return is >> t.max >> t.min;
}

