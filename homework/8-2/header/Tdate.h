//
// Created by 瑞彤 on 2025/5/8.
//

#ifndef OOP_TDATE_H
#define OOP_TDATE_H


class Tdate
{
public:
    Tdate();
    Tdate(int d);
    Tdate(int d, int m);
    Tdate(int d, int m, int y);
    //Tdate(int d, int m, int y, int& y);
    bool getDate(int& d, int& m, int& y);
    bool isLeapYear(void);
    void print(void);
    ~Tdate();

private:
    void init(int m, int d, int y);
    int day;
    int month;
    int year;
};


#endif //OOP_TDATE_H
