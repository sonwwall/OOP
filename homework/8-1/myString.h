//
// Created by 瑞彤 on 2025/5/8.
//

#ifndef OOP_MYSTRING_H
#define OOP_MYSTRING_H


// myString.h
class myString
{
public:
    myString(const char s[]);
    ~myString();
    void print() const;
    int getLen() const;
    const char* getString() const;
    myString(const myString& oldMyString);
private:
    char* ptrCharArray;
    int len;
};



#endif //OOP_MYSTRING_H
