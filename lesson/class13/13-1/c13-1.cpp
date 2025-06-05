//
// Created by 瑞彤 on 2025/5/29.
//

#include <iostream>

using namespace std;

class Complex{
public:
    Complex(double r,double i):real(r),imag(i){}
    Complex operator + (Complex &b);
    Complex operator +(double n);
    friend Complex operator+(double n, const Complex& c);
    void display(){
        cout<<"real:"<<real<<"  "<<"imag:"<<imag<<"i"<<endl;
    }
private:
    double real;
    double imag;
};

Complex Complex::operator+(Complex &b) {
    double r,i;
    r=real+b.real;
    i=imag+b.imag;
    return Complex(r,i);
}

Complex Complex::operator+(double n){
    double r,i;
    r=real+n;
    i=imag;
    return Complex(r,i);

}

Complex operator+(double n, const Complex& c) {
    return Complex(n + c.real, c.imag);
}

int main(){
    Complex a(2,5),b(7,8),c(0,0);
    c=a+b;
    c.display();
    c=a+4.1;
    c.display();
    c+4.1+a;
    c.display();

}

