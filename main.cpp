#include <iostream>
#include <filesystem>
#include <fstream>

using std::string, std::cout, std::endl;

void error(string message) {
    // The Error message
    cout << "Error: " << message << endl;
    cout << "Usage: ./grepfile -f [filename] -s 'WhatToGrepFor'" << endl;
    cout << "Commands:" << endl;
    cout << "\nhelp = Display this help message" << endl;
    cout << "-f [filename] = Pick the file to search in." << endl;
    cout << "-s [WhatToGrepFor] = What To look for in the file." << endl;
}

void help() {
    cout << "Usage: ./grepfile -f [filename] -s 'WhatToGrepFor'" << endl;
    cout << "Commands:" << endl;
    cout << "\nhelp = Display this help message" << endl;
    cout << "-f [filename] = Pick the file to search in." << endl;
    cout << "-s [WhatToGrepFor] = What To look for in the file." << endl;
}

bool exists(string filename) {
    return std::filesystem::exists(filename);
}

bool is_file(string filename) {
    return !std::filesystem::is_directory(filename);
}

string runfilechecks(int i, char* arguments[]) {
        if (!arguments[i + 1]) {
            // Check for filename present
            error("No filename provided");
            return "";
        }
        string filename = arguments[i + 1];
        if (!exists(filename)) {
            // Check if it exists
            cout << "File does not exist" << endl;
            return "";
        }
        if (!is_file(filename)) {
            // check if it is a folder.
            cout << filename << " is a folder. Please enter a file." << endl;
            return "";
        }
        // Tests passed.
        return filename;
}

string runsearchchecks(int i, char* arguments[]) {
    if (!arguments[i + 1]) {
        // Check for searchfor present
        error("Nothing provided to search for.");
        return "";
    }
    string searchfor = arguments[i + 1];
    // Tests passed.
    return searchfor;
}

int main(int argc, char *argv[]) {
    string filename;
    string searchfor;
    string line;
    int linecount = 1;
    if (!argv[1]) {
        error("No arguments provided");
        return 1;
    }
    if (argv[1] == string("help")) {
        help();
        return 1;
    }
    if (argv[1] == string("-help")) {
        help();
        return 1;
    }
    if (argv[1] == string("--help")) {
        help();
        return 1;
    }
    if (argv[1] == string("-h")) {
        help();
        return 1;
    }
    if (argv[1] == string("--h")) {
        help();
        return 1;
    }
    
    for (int i = 0; i < argc; i++) {
        if (argv[i] == string("-f")) {
            filename = runfilechecks(i, argv);
            if (filename == "") {
                return 1;
            }
        }
        else if (argv[i] == string("-s")) {
            searchfor = runsearchchecks(i, argv);
            if (searchfor == "") {
                return 1;
            }
        }
    }
    cout << "Searching file: " << filename << " for term: '" << searchfor << "'..." << endl;    
    std::ifstream inFile(filename);
    if (!inFile) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    bool found = false;

    // Read line-by-line and search for the term in each line
    while (std::getline(inFile, line)) {
        if (line.find(searchfor) != string::npos) {
            cout << "\nFound at line " << linecount << ":\n" << line << endl;
            found = true;
        }
        linecount++;
    }
    inFile.close();

    if (!found) {
        cout << "Term '" << searchfor << "' not found in file." << endl;
    }

    return 0;
}