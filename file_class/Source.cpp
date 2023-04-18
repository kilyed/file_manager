#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void write_to_file(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Error open file: " << filename << endl;
        return;
    }
    cout << "Enter text for file " << filename << " (!=exit):" << endl;
    string line;
    while (getline(cin, line) && line != "!") {
        file << line << endl;
    }
    file.close();
}

void append_to_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error open file: " << filename << endl;
        return;
    }
    cout << "Text in file " << filename << ":" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    cout << "Add text in file " << filename << " (!=exit):" << endl;
    ofstream outfile(filename, ios::app);
    while (getline(cin, line) && line != "!") {
        outfile << line << endl;
    }
    outfile.close();
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "How many file do you want open? ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string filename = to_string(i) + ".txt";
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error create file " << filename << endl;
        }
        else {
            cout << "File " << filename << " created." << endl;
            file.close();
        }
    }

    int choice;
    do {
        cout << "Choose file for redacted  (0=exit, -1=Added text in file): ";
        cin >> choice;
        if (choice < -1 || choice > n) {
            cerr << "Error input! " << n << "." << endl;
        }
        else if (choice == -1) {
            cout << "Enter number file for redacted: ";
            cin >> choice;
            if (choice < 1 || choice > n) {
                cerr << "Error input! " << n << "." << endl;
            }
            else {
                string filename = to_string(choice) + ".txt";
                append_to_file(filename);
            } 
        }
        else if (choice > 0) {
            string filename = to_string(choice) + ".txt";
            write_to_file(filename);
        }
    } while (choice != 0);

    cout << "Exit for programm" << endl;
 }
