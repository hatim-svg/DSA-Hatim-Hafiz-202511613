#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
using namespace std;

struct Student {
private:
    int id;
    string name;
    int age;
    string course;

public:
    // Constructor
    Student(int i = 0, string n = "", int a = 0, string c = "") {
        id = i;
        name = n;
        age = a;
        course = c;
    }

    // Getters
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getCourse() {
        return course;
    }

    // Setters
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    void setCourse(string c) {
        course = c;
    }

    // Display
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Course: " << course << endl;
        cout << "---------------------" << endl;
    }
};

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif