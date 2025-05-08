//
// Created by 瑞彤 on 2025/5/8.
//

#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H


// Student.h
#include "Tdate.h"
#include "myString.h"
#include "Person.h"

class Student : public Person//表示继承自Person,并且是无保留的继承，可以完全访问其父类
{
public:
    Student(const char * pName, const Tdate tBirthday, bool bSex, float fCredit);
    Student(const Student& oldStudent);
    void print(void);
protected:
    float credits;  //学分
};


#endif //OOP_STUDENT_H
