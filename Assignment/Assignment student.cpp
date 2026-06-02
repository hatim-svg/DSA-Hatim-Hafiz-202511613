#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string rollNumber;
    string name;
    int age;

    Student() : rollNumber(""), name(""), age(0) {}
    Student(string roll, string n, int a) : rollNumber(roll), name(n), age(a) {}

    string toCSV() const {
        return rollNumber + "," + name + "," + to_string(age);
    }
};

void displayAllStudents() {
    ifstream file("student.txt");
    if (!file) {
        cout << "\n[Error] Could not open file or file does not exist yet.\n";
        return;
    }

    string line;
    cout << "\n--- Student Records ---\n";
    cout << "Roll Number\tName\t\tAge\n";
    cout << "-------------------------------------\n";
    
    bool hasData = false;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string roll, name, ageStr;
        
        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        
        cout << roll << "\t" << name << "\t\t" << ageStr << "\n";
        hasData = true;
    }
    
    if (!hasData) {
        cout << "No student records found.\n";
    }
    file.close();
}

void searchStudent() {
    string searchRoll;
    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    ifstream file("student.txt");
    if (!file) {
        cout << "\n[Error] File not found.\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string roll, name, ageStr;

        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');

        if (roll == searchRoll) {
            cout << "\n--- Student Found ---\n";
            cout << "Roll Number: " << roll << "\n";
            cout << "Name:        " << name << "\n";
            cout << "Age:         " << ageStr << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found.\n";
    }
    file.close();
}

void updateStudent() {
    string searchRoll;
    cout << "\nEnter Roll Number to update: ";
    cin >> searchRoll;

    ifstream file("student.txt");
    if (!file) {
        cout << "\n[Error] File not found.\n";
        return;
    }

    vector<string> fileData;
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string roll;
        getline(ss, roll, ',');

        if (roll == searchRoll) {
            found = true;
            string newName;
            int newAge;
            
            cout << "Student found! Enter updated details:\n";
            cout << "Enter New Name: ";
            cin.ignore(); 
            getline(cin, newName);
            cout << "Enter New Age: ";
            cin >> newAge;

            
            Student updatedStudent(searchRoll, newName, newAge);
            fileData.push_back(updatedStudent.toCSV());
        } else {
            fileData.push_back(line);
        }
    }
    file.close();

    if (found) {
        
        ofstream outFile("student.txt", ios::trunc);
        for (const string& row : fileData) {
            outFile << row << "\n";
        }
        outFile.close();
        cout << "\nStudent information updated successfully!\n";
    } else {
        cout << "\nStudent not found.\n";
    }
}


void deleteStudent() {
    string searchRoll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> searchRoll;

    ifstream file("student.txt");
    if (!file) {
        cout << "\n[Error] File not found.\n";
        return;
    }

    vector<string> fileData;
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string roll;
        getline(ss, roll, ',');

        
        if (roll == searchRoll) {
            found = true;
        } else {
            fileData.push_back(line);
        }
    }
    file.close();

    if (found) {
        
        ofstream outFile("student.txt", ios::trunc);
        for (const string& row : fileData) {
            outFile << row << "\n";
        }
        outFile.close();
        cout << "\nRecord deleted permanently from the file.\n";
    } else {
        cout << "\nStudent not found.\n";
    }
}

void initializeFileIfEmpty() {
    ifstream file("C:\\Users\\HP\\OneDrive\\Desktop\\New folder\\student.txt");
    if (!file || file.peek() == ifstream::traits_type::eof()) {
        file.close();
        ofstream outFile("C:\\Users\\HP\\OneDrive\\Desktop\\New folder\\student.txt");
        if (outFile.is_open()) {
            outFile << "202312051,lithacynthia,18\n";
            outFile << "202312052,dessama,18\n";
            outFile << "202312053,david,20\n";
            outFile.close();
        }
    } else {
        file.close();
    }
}

int main() {
    initializeFileIfEmpty(); 
    int choice;

    do {
        cout << "\n==============================\n";
        cout << "1. Display All Students\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllStudents();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select an option between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}