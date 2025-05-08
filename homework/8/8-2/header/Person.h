//
// Created by 瑞彤 on 2025/5/8.
//

#ifndef OOP_PERSON_H
#define OOP_PERSON_H


// Person.h
#include "Tdate.h"
#include "myString.h"

class Person
{
public:
    Person(const char * pName, const Tdate tBirthday, bool bSex);
    Person(const Person& oldPerson);
    void print();
protected:
    myString name;
    Tdate birthday;
    bool sex;
};


#endif //OOP_PERSON_H
