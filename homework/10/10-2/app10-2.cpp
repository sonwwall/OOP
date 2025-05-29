//
// Created by 瑞彤 on 2025/5/22.
//

#include<iostream>

using namespace std;

class Geometry{
public:
    virtual double calculateVolume()const=0;
    virtual double calculateBaseArea()const=0;
    virtual void display()const=0;
};

class Cuboid:public Geometry{
public:
    Cuboid(double Length,double Width,double Height): Geometry(),L(Length),W(Width),H(Height){}
    virtual double calculateVolume()const{
        cout<<"长方体的体积为："<<endl;
        return L*W*H;
    }
    virtual double calculateBaseArea()const{
        cout<<"长方体的底面积为："<<endl;
        return L*W;
    }
    virtual void display()const{
        cout<<"长方体的长为："<<L<<"，宽为："<<W<<"，高为："<<H<<endl;
    }

protected:
    double L,W,H;
};

class Cone:public Geometry{
public:
    Cone(double Radius,double Height): Geometry(),R(Radius),H(Height){}
    virtual double calculateVolume()const{
        cout<<"圆锥体的体积为："<<endl;
        return (3.14*R*R*H)/3;
    }
    virtual double calculateBaseArea()const{
        cout<<"圆锥体的底面积为："<<endl;
        return 3.14*R*R;
    }
    virtual void display()const{
        cout<<"圆锥体的底面半径为："<<R<<"，高为："<<H<<endl;
    }

private:
    double R,H;
};

class Cylinder:public Geometry{
public:
    Cylinder(double Radius,double Height): Geometry(),R(Radius),H(Height){}
    virtual double calculateVolume()const{
        cout<<"圆柱体的体积为："<<endl;
        return (3.14*R*R*H);
    }
    virtual double calculateBaseArea()const{
        cout<<"圆柱体的底面积为："<<endl;
        return 3.14*R*R;
    }
    virtual void display()const{
        cout<<"圆柱体的底面半径为："<<R<<"，高为："<<H<<endl;
    }

private:
    double R,H;


};

void printVolume(Geometry * geom){
    geom->display();
    cout<<geom->calculateVolume()<<endl;
    cout<<geom->calculateBaseArea()<<endl;
}

int main(){
    Cuboid cub(10,20,30);
    printVolume(&cub);
    Cone con(10,10);
    printVolume(&con);
    Cylinder cyl(10,20);
    printVolume(&cyl);

    Geometry* shapes[] = { &cub, &con, &cyl };

    // 遍历数组并调用 printVolume
    for (int i = 0; i < 3; ++i) {
        printVolume(shapes[i]);
        cout << "--------------------------" << endl;
    }
}