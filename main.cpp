#include <iostream>
#include <filesystem>

using std::string, std::cout, std::endl;

void help(string message) {
    cout << "Error: " << message << endl;
    cout << 'Usage: ./main -f [filename] ""' << endl;
    cout << "Commands:" << endl;
    cout << "\nhelp = Display this help message" << endl;
    cout << "-f [filename] = Display the version of the program" << endl;
}

void help() {
    cout << "Usage: ./main [command] [argument]" << endl;
    cout << "Commands:" << endl;
    cout << "\nhelp = Display this help message" << endl;
    cout << "-f [filename] = Display the version of the program" << endl;
}

bool exists(string filename) {
    return std::filesystem::exists(filename);
}

bool is_file(string filename) {
    return !std::filesystem::is_directory(filename);
}

int main(int argc, char *argv[]) {
    if (!argv[1]) {
        help("No arguments provided");
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
    
    if (argv[1] == string("-f")) {
        if (!argv[2]) {
            help("No filename provided");
            return 1;
        }
        string filename = argv[2];
        cout << "File name: " << filename << endl;
        if (!exists(filename)) {
            cout << "File does not exist" << endl;
            return 1;
        }
        if (!is_file(filename)) {
            cout << filename << " is a folder. Please enter a file." << endl;
            return 1;
        }
        cout << "File exists..." << endl;
    }

    return 0;
}