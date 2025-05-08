//
// Created by 瑞彤 on 2025/5/8.
//



// myString.cpp
#include "myString.h"
#include <iostream>
using namespace std;

//构造函数
myString::myString(const char s[]) {
    len = strlen(s);//获取字符串长度
    ptrCharArray = new char[len + 1];//分配内存
    strncpy(ptrCharArray, s, len + 1);//copy进去
    ptrCharArray[len] = '\0';//加上\0
}

myString::~myString() {
    delete ptrCharArray;
}

void myString::print() const {
    cout << ptrCharArray << endl;
}

int myString::getLen() const {
    return len;
}

const char* myString::getString() const {
    return ptrCharArray;
}

//复制构造函数
myString::myString(const myString& oldMyString) {
    len = oldMyString.getLen();
    ptrCharArray = new char[len + 1];
    strncpy(ptrCharArray, oldMyString.getString(), len + 1);
}

