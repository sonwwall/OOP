//
// Created by 瑞彤 on 2025/5/8.
//


#include "../header/Tdate.h"
#include "../header/myString.h"
#include "../header/Person.h"
#include <iostream>
using namespace std;

Person::Person(const char * pName, const Tdate tBirthday, bool bSex) : name(pName), birthday(tBirthday)
{
    sex = bSex;
}

Person::Person(const Person& oldPerson) : name(oldPerson.name), birthday(oldPerson.birthday)
{
    sex = oldPerson.sex;
}

void Person::print()
{
    name.print();
    cout << ",";
    birthday.print();
    cout << "," << (sex ? "男" : "女");
}
