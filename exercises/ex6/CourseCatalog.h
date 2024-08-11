#include "includes.h"

class CourseCatalog {
    private:
    map<string, string> course;

    public:
    CourseCatalog();
    void addCourse(const string& courseCode, const string& courseText);
    // Updates the course content if it is not empty. If empty; throws error.
    void updateCourse(const string& courseCode, const string& courseName);
    // Add the course and update it if it already exists.
    void forceAddCourse(const string& courseCode, const string& courseName);
    void removeCourse(const string& courseCodeOrText);
    string getCourse(const string& courseCode);
    // Read a structured file and adds the content to a map.
    void loadMap(const string& fileName);
    // Save map to a file.
    void saveMap(const string& fileName);
    friend ostream& operator << (ostream& os, const CourseCatalog& cc);
    // void addCourse(map<string, string> courses);

};