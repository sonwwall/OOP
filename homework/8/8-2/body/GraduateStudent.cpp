//
// Created by 瑞彤 on 2025/5/8.
//

// GraduateStudent.cpp
#include "../header/Student.h"
#include "../header/Teacher.h"
#include "../header/GraduateStudent.h"
#include <iostream>
using namespace std;

GraduateStudent::GraduateStudent(Student& s, Teacher& t) : Student(s)
{
    supervisor = &t;
}

GraduateStudent::GraduateStudent(const GraduateStudent& oldGraduateStudent) : Student(oldGraduateStudent)
{
    supervisor = oldGraduateStudent.supervisor;
}

void GraduateStudent::print()
{
    cout << "GraduateStudent:" << endl;
    Student::print();
    cout << endl;
    supervisor->print();
}