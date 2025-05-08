//
// Created by 瑞彤 on 2025/5/8.
//

// Student.cpp
#include "../header/Tdate.h"
#include "../header/myString.h"
#include "../header/Person.h"
#include "../header/Student.h"
#include <iostream>
using namespace std;

Student::Student(const char * pName, const Tdate tBirthday, bool bSex, float fCredit) : Person(pName, tBirthday, bSex)//同时调用了父类的方法
{
    credits = fCredit;
}

Student::Student(const Student& oldStudent) : Person(oldStudent)
{
    credits = oldStudent.credits;
}

void Student::print()
{
    cout << "Student:" << endl;
    Person::print();
    cout << "," << credits;
}