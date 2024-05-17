#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to hold student information
struct Student {
    int rollNumber;
    string name;
    char division;
    string address;
};

// Function to add student information to file
void addStudentInfo() {
    ofstream outFile("student.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    Student student;
    cout << "Enter Roll Number, Name, Division, and Address: ";
    cin >> student.rollNumber >> student.name >> student.division >> student.address;

    outFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
    cout << "Student information added successfully." << endl;

    outFile.close();
}

// Function to delete student information from file
void deleteStudentInfo() {
    ifstream inFile("student.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    int rollNumberToDelete;
    cout << "Enter Roll Number to delete: ";
    cin >> rollNumberToDelete;

    bool found = false;
    Student student;

    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber != rollNumberToDelete) {
            tempFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found) {
        cout << "Student information deleted successfully." << endl;
    } else {
        cout << "Student information with Roll Number " << rollNumberToDelete << " not found." << endl;
    }
}

// Function to display information of a particular student
void displayStudentInfo() {
    ifstream inFile("student.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    int rollNumberToFind;
    cout << "Enter Roll Number to find: ";
    cin >> rollNumberToFind;

    bool found = false;
    Student student;

    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumberToFind) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found) {
        cout << "Student information with Roll Number " << rollNumberToFind << " not found." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nMENU\n";
        cout << "1. Add Student Information\n";
        cout << "2. Delete Student Information\n";
        cout << "3. Display Student Information\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentInfo();
                break;
            case 2:
                deleteStudentInfo();
                break;
            case 3:
                displayStudentInfo();
                break;
            case 4:
                cout << "Exiting...";
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

