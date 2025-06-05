//
// Created by 瑞彤 on 2025/6/5.
//


#include <iostream>
#include "string"

using namespace  std;


class Student{
private:
    string name;
    string id;

public:
    Student(string n,string i){
        name=n;
        id=i;
    }
    void print(){
        cout<<"姓名："<<name<<",";
        cout<<"学号："<<id<<endl;
    }
};

class Classroom{
private:
    Student* students[5];
public:
    Classroom(){
        for(int i=0;i<5;i++){
            students[i]= nullptr;
        }
    }
    bool add(Student* stu){
        for(int i=0;i<5;i++){
            if (students[i]== nullptr){
                students[i]=stu;
                break;
            }
        }
    }
    void print(){
        for(int i=0;i<5;i++){
            if(students[i]){
                students[i]->print();
            }
        }
    }
};

int main(){
    Student stu1("张三","1001");
    Student stu2("李四","1002");
    Student stu3("王五","1003");
    Classroom classroom;
    classroom.add(&stu1);
    classroom.add(&stu2);
    classroom.add(&stu3);

    classroom.print();
}