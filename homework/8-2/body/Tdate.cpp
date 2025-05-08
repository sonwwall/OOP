//
// Created by 瑞彤 on 2025/5/8.
//

#include "../header/Tdate.h"

#include <iostream>
using namespace std;

void Tdate::init(int d, int m, int y){
    day = d;
    month = m;
    year = y;
    cout << "构造:";
    print();
}

Tdate::Tdate(){
    init(23, 7, 2021);
}

Tdate::Tdate(int d){
    init(d, 7, 2021);
}

Tdate::Tdate(int d, int m){
    init(d, m, 2021);
}

Tdate::Tdate(int d, int m, int y){
    init(d, m, y);
}

bool Tdate::isLeapYear(){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Tdate::print(){
    cout << month << "/" << day << "/" << year << endl;
}

Tdate::~Tdate(){
    cout << "析构:";
    print();
}
