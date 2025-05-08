//
// Created by 瑞彤 on 2025/5/8.
//

#include "header/Person.h"

#include "header/Teacher.h"
#include "header/GraduateStudent.h"
#include <iostream>
using namespace std;

const bool male = true;
const bool female = false;

int main(){
    cout << "**** 创建 Person 对象 *****" << endl;
    Person p1("张三", Tdate(8, 8, 2021), male);
    p1.print();

    cout << endl << "**** 创建 Student 对象 *****" << endl;
    Student s1("李四", Tdate(8, 8, 2021), female, 20);
    s1.print();

    cout << endl << "**** 创建 Teacher 对象 *****" << endl;
    Teacher t1(p1);
    t1.print();

    cout << endl << "**** 创建 GraduateStudent 对象 *****" << endl;
    GraduateStudent g1(s1, t1);
    g1.print();

    cout << endl << endl << "**** main 语句结束 *****" << endl;

}