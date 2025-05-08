//
// Created by 瑞彤 on 2025/5/8.
//

// Teacher.cpp
#include "../header/Person.h"
#include "../header/Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher(const Person& p) : Person(p)
{
}

Teacher::Teacher(const Teacher& oldTeacher) : Person(oldTeacher)
{
}

void Teacher::print()
{
    cout << "Teacher:" << endl;
    Person::print();
}