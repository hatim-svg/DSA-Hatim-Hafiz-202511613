#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    int age;
    std::string course;
};


extern std::vector<Student> studentList;

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif