#include "ListHandling.h"

// Vector handling (Iterators)

void printVector(vector<string>& vec) {
    cout << "[ ";
    for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << "]" << endl;
}

void printReverseVector(vector<string>& vec) {
    cout << "[ ";
    for(vector<string>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
        cout << *it << " ";
    cout << "]" << endl;
}

void replaceVectorElement(vector<string>& vec, string oldValue, string newValue) {
    for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
        if(*it == oldValue){
            it = vec.erase(it);
            it = vec.insert(it, newValue);
        }
    }
}

// Set handling (iterators)


void printSet(set<string>& set1) {
    cout << "[ ";
    for(set<string>::iterator it = set1.begin(); it != set1.end(); it++)
        cout << *it << " ";
    cout << "]" << endl;
}

void printReverseSet(set<string>& set1) {
    cout << "[ ";
    for(set<string>::reverse_iterator it = set1.rbegin(); it != set1.rend(); it++)
        cout << *it << " ";
    cout << "]" << endl;
}

void replaceSetElement(set<string>& set1, string oldValue, string newValue) {
    // Since a set has unique values, make sure one does not erase without inserting a value.
    if(set1.count(newValue)) {
        cout << "No change: The new value already exists in the set." << endl;
        return;
    }

    set<string>::iterator it = set1.find(oldValue);
    if(it != set1.end()) {
        it = set1.erase(it);
        it = set1.insert(it, newValue);
    }

}