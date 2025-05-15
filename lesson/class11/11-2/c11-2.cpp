#include <iostream>

using namespace std;

class Number{
public:
    virtual unsigned add(unsigned n);//只有加上virtual才能实现分类别调用，如果后面加上=0则可以不实现这个函数，否则必须实现
    unsigned digits;
};

unsigned Number::add(unsigned n){
    cout<<"Number+Number"<<endl;
    return 0;
}

class Real:public Number{
public:
    virtual unsigned add(unsigned n);
    unsigned add(double);
};

class Int:public Number{
public:
    virtual unsigned add(unsigned n);
    unsigned add(int,int);
};

unsigned Int::add(unsigned n){
    cout<<"整数+整数"<<endl;
    return 0;
};

unsigned Int::add(int n,int m){
    cout<<"整数+整数（重载）"<<endl;
    return 0;
}

unsigned Real::add(unsigned n){
    cout<<"实数+实数"<<endl;
    return 0;
}

unsigned Real::add(double n){
    cout<<"实数+实数（重载）"<<endl;
    return 0;
}

void fAdd(Number &op1,Number &op2){
    op1.add(op2.digits);
}

int main(){
    cout<<"****实数的加法****"<<endl;
    Real r1,r2;
    fAdd(r1,r2);
    r1.add(3.14);
    cout<<"****整数的加法****"<<endl;
    Int i1,i2;
    fAdd(i1,i2);
    i1.add(2,3);

}