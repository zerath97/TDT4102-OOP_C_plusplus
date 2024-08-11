#include "includes.h"



void writeWordToFile(const string& fileName) {
    string word = "";
    ofstream ofs{ fileName };

    if (!ofs) return error("Can't open output file ", fileName);
    ofs << "------------------------------------------------" << endl;
    
    while(true) {
        cout << "Enter \"quit\" to exit." << endl << endl;
        cout <<"Enter a word: ";
        cin >> word;
        
        if(word == "quit" && word.size() == 4)
            break;
        
        ofs << word << endl;
    }
}

void appendWordToFile(const string& fileName) {
    string word = "";
    ofstream ofs{ fileName, ios_base::app};

    if (!ofs) return error("Can't open output file ", fileName);
    ofs << "------------------------------------------------" << endl;
    
    while(true) {
        cout << "Enter \"quit\" to exit." << endl << endl;
        cout <<"Enter a word: ";
        cin >> word;
        
        if(word == "quit" && word.size() == 4)
            break;
        
        ofs << word << endl;
    }
}

void readLineFromFile(const string& fileName, vector<string>& text) {
    ifstream ist{ fileName };
    if (!ist)
        return error("Can't open input file ", fileName);


    for ( string line; getline(ist, line); )
        text.push_back(line);
}


void readAndWriteFile(const string& fileName) {
    
    vector<string> text;

    readLineFromFile(fileName, text);

    string fileNameEdit = fileName;
    
    for (const char& c : "txt")
        fileNameEdit.pop_back();
    
    fileNameEdit += "_linenums.txt";
    
    ofstream ofs{ fileNameEdit };

    int i = 1;

    for(auto line : text)
        ofs << to_string(i++) << "\t" << line << endl;
    
}

map<char, int> countCharsInFile(const string& fileName) {

    vector<string> text;
    readLineFromFile(fileName, text);

    map<char, int> charCounter;
    
    for(const string& line : text){
        for(unsigned int i = 0; i < line.length(); i++)
            charCounter[tolower(line[i])] += 1;
    }

    return charCounter;
}