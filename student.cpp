#include "student.h"

vector<Student> students;

// Add student
void addStudent() {
    int id, age;
    string name, course;

    cout << "Enter Student ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, course);

    Student s(id, name, age, course);
    students.push_back(s);

    cout << "Student Added Successfully!\n";
}

// Display students
void displayStudents() {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}

// Search student
void searchStudent() {
    int id;
    cout << "Enter Student ID to Search: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students[i].display();
            return;
        }
    }

    cout << "Student Not Found.\n";
}

// Update student
void updateStudent() {
    int id;
    cout << "Enter Student ID to Update: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {

            string name, course;
            int age;

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, name);

            cout << "Enter New Age: ";
            cin >> age;

            cin.ignore();

            cout << "Enter New Course: ";
            getline(cin, course);

            students[i].setName(name);
            students[i].setAge(age);
            students[i].setCourse(course);

            cout << "Student Updated Successfully!\n";
            return;
        }
    }

    cout << "Student Not Found.\n";
}

// Delete student
void deleteStudent() {
    int id;
    cout << "Enter Student ID to Delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);

            cout << "Student Deleted Successfully!\n";
            return;
        }
    }

    cout << "Student Not Found.\n";
}