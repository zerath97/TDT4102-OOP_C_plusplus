#include "includes.h"

class Person {
    private:

    string firstName;
    string surName;

    public:
    Person();
    Person(string firstName, string surName) : firstName{firstName}, surName{surName} {}
    ~Person();
    string get_firstName() {return firstName;}
    void set_firstName(string newName) {firstName = newName;}
    string get_surName() {return surName;}
    void set_surName(string newName) {surName = newName;}

    ostream& operator << (ostream& os) {
        os << "First name: " << firstName << endl << "Surname: " << surName;
    }
};