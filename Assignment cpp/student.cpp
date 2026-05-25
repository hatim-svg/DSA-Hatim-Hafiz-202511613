#include "student.h"
#include <iostream>


std::vector<Student> studentList;

void addStudent() {
    Student newStudent;
    std::cout << "\n--- Add New Student ---\n";
    std::cout << "Enter Student ID: ";
    std::cin >> newStudent.id;
    std::cin.ignore();
    std::cout << "Enter Name: ";
    std::getline(std::cin, newStudent.name);
    std::cout << "Enter Age: ";
    std::cin >> newStudent.age;
    std::cin.ignore();
    std::cout << "Enter Course: ";
    std::getline(std::cin, newStudent.course);

    studentList.push_back(newStudent);
    std::cout << "Student added successfully!\n";
}

void displayStudents() {
    std::cout << "\n--- Student List ---\n";
    if (studentList.empty()) {
        std::cout << "No student records found.\n";
        return;
    }
    for (const auto& s : studentList) {
        std::cout << "ID: " << s.id << " | Name: " << s.name << " | Age: " << s.age << " | Course: " << s.course << "\n";
    }
}

void searchStudent() {
    std::cout << "\n--- Search Student ---\n";
    if (studentList.empty()) {
        std::cout << "No student records found.\n";
        return;
    }
    int searchId;
    std::cout << "Enter Student ID: ";
    std::cin >> searchId;
    for (const auto& s : studentList) {
        if (s.id == searchId) {
            std::cout << "Found! Name: " << s.name << " | Course: " << s.course << "\n";
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void updateStudent() {
    std::cout << "\n--- Update Student ---\n";
    if (studentList.empty()) {
        std::cout << "No student records found.\n";
        return;
    }
    int updateId;
    std::cout << "Enter ID to update: ";
    std::cin >> updateId;
    for (auto& s : studentList) {
        if (s.id == updateId) {
            std::cin.ignore();
            std::cout << "Enter New Name: ";
            std::getline(std::cin, s.name);
            std::cout << "Enter New Age: ";
            std::cin >> s.age;
            std::cin.ignore();
            std::cout << "Enter New Course: ";
            std::getline(std::cin, s.course);
            std::cout << "Updated successfully!\n";
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void deleteStudent() {
    std::cout << "\n--- Delete Student ---\n";
    if (studentList.empty()) {
        std::cout << "No student records found.\n";
        return;
    }
    int deleteId;
    std::cout << "Enter ID to delete: ";
    std::cin >> deleteId;
    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if (it->id == deleteId) {
            studentList.erase(it);
            std::cout << "Deleted successfully!\n";
            return;
        }
    }
    std::cout << "Student not found.\n";
}