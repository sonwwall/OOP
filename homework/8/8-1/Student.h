//
// Created by 瑞彤 on 2025/5/8.
//

#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H


#include "myString.h"
#include <iostream>
using namespace std;

class Student
{
public:
    static int number(void);
    static Student* findname(const char* pName);
    Student(const char* pName);
    ~Student();
private:
    myString name;             // 存储组合关联 name 中的连接
    Student* pNext;            // 指向链表中的下一个 Student 对象
    static Student* pFirst;    // 指向链表中的第一个 Student 对象
    static int noOfStudents;   // 存储学生人数
};



#endif //OOP_STUDENT_H
