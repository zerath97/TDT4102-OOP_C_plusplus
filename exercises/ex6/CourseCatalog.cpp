#include "includes.h"

CourseCatalog::CourseCatalog() {}

void CourseCatalog::addCourse(const string& courseCode, const string& courseName) {
    course.insert(pair<string, string>(courseCode, courseName));
}

void CourseCatalog::updateCourse(const string& courseCode, const string& courseName) {
    if(!course[courseCode].empty())
        course[courseCode] = courseName;
    else
        return error("The course does not exist.");
}

void CourseCatalog::forceAddCourse(const string& courseCode, const string& courseName) {
    course[courseCode] = courseName;
}

// void CourseCatalog::addCourse(map<string, string> courses) {
//     for(const auto& c : courses)
//         course[c.first] = c.second;
// }

void CourseCatalog::removeCourse(const string& courseCode) {
    course[courseCode].erase();
}

string CourseCatalog::getCourse(const string& courseCode) {
    return course[courseCode];
}

void CourseCatalog::loadMap(const string& fileName) {
    ifstream ist( fileName );

    if(!ist)
        return error("Cannot open input file: ", fileName);

    for(string line; getline(ist, line);) {
        pair<string, string> temp;
        unsigned int e = 0;

        // Adds the coursecode to the pair.first.
        for(unsigned int i = 0; line[i] != ' '; i++) {
            temp.first += line.at(i);   
            e++;
        }
        // Adds the coursename to the pair.second.
        for(e += 3; e < line.length(); e++)
            temp.second += line.at(e);

        // Adds the pair to the object's map.
        course[temp.first] = temp.second;
    }
}

void CourseCatalog::saveMap(const string& fileName) {
    ofstream ost( fileName );
    
    if(!ost)
        return error("Cannot open output file: ", fileName);

    for(const auto& c : course) {
        ost << c.first << " = " << c.second << endl;
    }
}


ostream& operator << (ostream& os, const CourseCatalog& cc) {
    os  << "-------------------------------------------------------------------------------------------------" << endl;
    os  << "|| Coursecode:" << "\t" << "|" << "\t" << "Course name:" << endl
        << "|| ----------------------------------------------------------------------------------------------" << endl;
    for(const auto& course : cc.course)
        os << "|| [" << course.first << "] \t" << "|" << "\t" << "\"" << course.second << "\"" << endl;
    os << "--------------------------------------------------------------------------------------------------" << endl;
    return os;
}