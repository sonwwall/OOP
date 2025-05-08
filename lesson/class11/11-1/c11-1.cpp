//
// Created by 瑞彤 on 2025/5/8.
//

class Base{
public:
    int m1;
protected:
    int m2;//可以在继承的类中访问，但是不能在任何实例中访问

public:
    int test(){
        m1=1;
        m2=2;
        m3=3;
        return 0;

    }
private:
    int m3;//只能在本类中访问

};

//把所有的变为private
class PrivateClass:private Base{
    int test(){
        m1=1;
        m2=2;
        //m3=3;
        return 0;
    }
};

//相当于把public变为protected
class ProtectedClass: protected Base{
    int test(){
        m1=1;
        m2=2;
        //m3=3;
        return 0;
    }
};

//不变
class PublicClass: public Base{
    int test(){
        m1=1;
        m2=2;
        //m3=3;
        return 0;
    }
};

//因为全部变为private所以都无法访问
class DerivedFromPri:public PrivateClass{
    int test(){
        //m1=1;
        return 0;
    }
};

//m1,m2为protected可以访问
class DerivedFromPro:public ProtectedClass{
    int test(){
        m1=1;
        m2=2;
        //m3=3;
        return 0;
    }
};

//m1为public，m2为protected可以使用
class DerivedFromPub:public PublicClass{
    int test(){
        m1=1;
        m2=2;
        //m3=3;
        return 0;
    }
};

int main(){
    Base base;
    base.m1=1;
    base.test();

    PrivateClass pri;//都是private，无法实例访问
    ProtectedClass pro;//m1,m2是protected和m3private无法访问
    //pro.m2;
    PublicClass pub;//m1为public可以访问，剩下两个分别为public和private
    pub.m1;

    DerivedFromPri Dpri;//同上
    DerivedFromPro Dpro;
    DerivedFromPub Dpub;
    Dpub.m1;

}