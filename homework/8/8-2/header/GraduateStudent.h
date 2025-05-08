//
// Created by 瑞彤 on 2025/5/8.
//

#ifndef OOP_GRADUATESTUDENT_H
#define OOP_GRADUATESTUDENT_H


// GraduateStudent.h
#include "Student.h"
#include "Teacher.h"

class GraduateStudent : public Student
{
public:
    GraduateStudent(Student& s, Teacher& t);
    //GraduateStudent(Student& s, Teacher t);
    GraduateStudent(const GraduateStudent& oldGraduateStudent);
    void print(void);
protected:
    Teacher* supervisor;
};


#endif //OOP_GRADUATESTUDENT_H
