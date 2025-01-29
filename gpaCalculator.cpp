#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Record {
private:
    fstream outFile;

public:
    // Constructor to open a file
    Record() {
        outFile.open("Student Record.txt", ios::out | ios::app | ios::ate);
        if (!outFile.is_open()) {
            cerr << "Unable to open file!" << endl;
        }
    }

    // Method to calculate CGPA and write to file
    void writeToFile(const char* name, float percentage) {
        float CGPA = (percentage / 100) * 4; // Calculate CGPA
        outFile << name << "\t\t" << CGPA << endl; // Write to file

        // Output in Console
        cout << "Name\tCGPA\n";
        cout << name << "\t" << CGPA << endl;
    }

    // Destructor to close the file
    ~Record() {
        if (outFile.is_open()) {
            outFile.close();
        }
    }
};

int main() {
    Record obj; 
    float percentage;
    char name[22];

    cout << "Enter your name: ";
    fgets(name, sizeof(name), stdin); 
    
    name[strcspn(name, "\n")] = '\0'; // Remove newline character using strcspn

    cout << "Enter your percentage obtained: ";
    cin >> percentage;//User input

    if (percentage > 100 ||percentage<0) {
        cout << "Invalid input!" << endl;
        return 1;
    }

    obj.writeToFile(name, percentage); // Call the writeToFile method
    return 0;
}