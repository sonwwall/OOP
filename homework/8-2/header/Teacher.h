//
// Created by 瑞彤 on 2025/5/8.
//

#ifndef OOP_TEACHER_H
#define OOP_TEACHER_H


// Teacher.h
#include "Person.h"
#include "Student.h"
#include "Teacher.h"

class Teacher:public Person
{
public:
    Teacher(const Person& p);
    Teacher(const Teacher& oldTeacher);
    void print();
};


#endif //OOP_TEACHER_H
