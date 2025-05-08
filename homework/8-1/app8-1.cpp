//
// Created by 瑞彤 on 2025/5/8.
//

#include "myString.h"
#include "Student.h"



int main() {
    Student s1("Randy");
    new Student("Jenny");
    Student s2("Kinsey");

    cout << "查找 Jenny:";
    Student* pS1 = Student::findname("Jenny");
    if (pS1)
        cout << "ok." << endl;
    else
        cout << "no find." << endl;

    delete pS1;

    cout << "查找 Jenny:";
    Student* pS2 = Student::findname("Jenny");
    if (pS2)
        cout << "ok." << endl;
    else
        cout << "no find." << endl;

    return 0;
}
