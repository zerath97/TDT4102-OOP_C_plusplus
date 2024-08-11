#include "includes.h"

class Temps {
    private:
    double min, max;

    public:
    Temps();
    vector<vector<double>> readTemps(const string& fileName);
    void tempStats(vector<vector<double>> temps);  
    friend istream& operator >> (istream& is, Temps& t);
};

double getMin(vector<vector<double>> doubleVector, unsigned int& index);
double getMax(vector<vector<double>> doubleVector, unsigned int& index);