//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "includes.h"

//------------------------------------------------------------------------------'

void addSomeCourses(CourseCatalog& cc2, map<string, string> courses) {
	

	for(const auto& c : courses)
		cc2.addCourse(c.first, c.second);
	
	// 3d) Changes the course value to "TDT4102."
	// cc2.addCourse("TDT4102", "TDT4102");
	// cc2.updateCourse("TDT4102", "TDT4102");
	cc2.forceAddCourse("TDT4102", "TDT4102");
	cout << cc2;
	}


void loadSomeCourses(CourseCatalog& cc2) {
	string fileName = "map.txt";
	cc2.loadMap(fileName);

	cc2.forceAddCourse("TDT4102", "TDT4102");
	cc2.saveMap(fileName);
	cout << cc2;
}

// C++ programs start by executing the function main
int main()
{
	// vector<string> test;
	
{	// Task 1

	// writeWordToFile("example.txt");
	// readLineFromFile("example.txt", test);

	// readAndWriteFile("example.txt");
}

{	// Task 2a)

	// map<char, int> countChars = countCharsInFile("example.txt");
	// for(const auto& c : countChars)
	// 	cout << "[" << c.first << "]: " << c.second << endl;
}

{	// Task 3
	// map<string, string> courses = {{"TDT4110", "Informasjonsteknologi grunnkurs"}, {"TDT4102", "Prosedyre- og objektorientert programmering"}, {"TMA4100", "Matematikk 1"}};
	// CourseCatalog cc2;
	
	//addSomeCourses(cc2, courses);
	// addSomeCourses(cc2, courses);
	// cc2.saveMap("map.txt");
	// loadSomeCourses(cc2);
}

{	// Task 4
	// c)
	Temps t1;
	vector<vector<double>> test1 = t1.readTemps("temperatures.txt");
	for(const auto& t : test1)
		cout << t.at(0) << " , " << t.at(1) << endl; 
	
	// d)
	t1.tempStats(test1);

}

keep_window_open();
}

//------------------------------------------------------------------------------
