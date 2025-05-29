//
// Created by 瑞彤 on 2025/5/15.
//
#include <cmath>
#include <iostream>

using namespace std;

class Shape{
public:
    Shape(double x,double y):xCoord(x),yCoord(y){}
    virtual double area()const=0;
    virtual double perimeter()const=0;
protected:
    double xCoord,yCoord;
};

class Circle:public Shape{
public:
    Circle(double x,double y ,double r): Shape(x,y),radius(r){}
    virtual double area()const{
        cout<<"圆的半径为："<<radius <<"圆的面积为："<<endl;
        return 3.14*radius*radius;
    }
    virtual double perimeter()const{
        cout<<"圆的半径为："<<radius<<"圆的周长为："<<endl;
        return 2*3.14*radius;
    }
protected:
    double radius;
};

class Rectangle:public Shape{
public:Rectangle(double x1,double y1,double x2,double y2):Shape(x1,y1),x2Coord(x2),y2Coord(y2){}
    virtual double area()const;
    virtual double perimeter()const;
protected:double x2Coord,y2Coord;
};

double Rectangle::area()const{
    cout<<"长方形的长宽为:"<<xCoord-x2Coord<<","<<yCoord-y2Coord<<"长方形的面积为："<<endl;
    return fabs((xCoord-x2Coord)*(yCoord-y2Coord));
}

double Rectangle::perimeter() const {
    cout<<"长方形的长宽为:"<<xCoord-x2Coord<<","<<yCoord-y2Coord<<"长方形的周长为："<<endl;
    return 2*(xCoord-x2Coord)+2*(yCoord-y2Coord);
}

class Delta:public Shape{
public:Delta(double x1,double y1,double d1,double d2,double d3): Shape(x1,y1),side1(d1),side2(d2),side3(d3){}
    virtual double area()const;
    virtual double perimeter()const;
protected:double side1,side2,side3;
};

double Delta::area() const {
    cout<<"三角形三边为"<<side1<<","<<side2<<","<<side3<<"三角形的面积为："<<endl;
    double p=side1+side2+side3;
    double area= sqrt(p*(p-side1)*(p-side2)*(p-side3));
    return area;
}

double Delta::perimeter() const {
    cout<<"三角形三边为"<<side1<<","<<side2<<","<<side3<<"三角形的周长为："<<endl;
    return side1+side2+side3;
}


void compute(const Shape& sp){
    cout<<sp.area() <<endl;
}

void perimeter(const Shape&sp){
    cout<<sp.perimeter() <<endl;
}

int main(){
    Circle c(2.0,3.0,4.0);
    compute(c);
    perimeter(c);
    Rectangle r(2.0,4.0,1.0,2.0);
    compute(r);
    perimeter(r);
    Delta d(2.0,3.0,3,4,5);
    compute(d);
    perimeter(d);



}