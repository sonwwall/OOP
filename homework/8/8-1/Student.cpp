//
// Created by 瑞彤 on 2025/5/8.
//

#include "Student.h"

int Student::noOfStudents = 0;//记录学生总数
Student* Student::pFirst = NULL;//指向第一个学生

//返回学生总数
int Student::number(void) {
    return noOfStudents;
}

//根据名字查找一个学生，返回该学生的指针
//使用一个简单的链表遍历（通过 pNext 指针）。
//遍历过程中，调用 name.getString() 获取学生的名字，并与传入的 pName 进行比较。
Student* Student::findname(const char* pName) {
    for (Student* pS = pFirst; pS; pS = pS->pNext)
        if (strcmp(pS->name.getString(), pName) == 0)
            return pS;
    return NULL;
}

//构造函数接受一个名字 pName，并将其传递给 name 成员（name 是一个假设存在的 MyString 类的对象，代表学生名字）。
//每次创建一个新的学生对象时，会将新创建的对象插入到链表的头部（pNext = pFirst），这样最新创建的学生对象将成为第一个学生。
//然后将 pFirst 更新为当前对象（this），表示链表头指针指向这个新创建的对象。
Student::Student(const char* pName) : name(pName) {
    cout << "插入:" << this->name.getString() << endl;
    pNext = pFirst;            // 每新建一个结点(对象)，就将其挂在链首
    pFirst = this;
}

//如果当前对象是链表的第一个学生（即 pFirst == this），只需将 pFirst 更新为当前对象的 pNext，即可删除当前对象。
//如果当前对象不是链表头，则通过遍历链表，找到当前对象的前一个节点，并将其 pNext 更新为当前对象的 pNext，从而删除当前对象并重新链接链表。
Student::~Student() {
    cout << "删除:" << this->name.getString() << endl;

    if (pFirst == this) {     // 如果要删除链首结点, 只要链首指针指向下一个
        pFirst = pNext;
        return;
    }

    for (Student* pS = pFirst; pS; pS = pS->pNext) {
        if (pS->pNext == this) { // 找到时, pS 指向当前结点的前一个结点
            pS->pNext = pNext;   // pNext 即 this -> pNext
            return;
        }
    }
}
