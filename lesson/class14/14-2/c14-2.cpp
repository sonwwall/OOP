//
// Created by 瑞彤 on 2025/6/5.
//

#include "string"
#include <iostream>

using namespace std;

class Product{
protected:
    string name;
    double price;
public:
    Product(string Name,double Price):name(Name),price(Price){}
    virtual void getPrice()const=0;
};

class NormalProduct: public Product{
public:
    NormalProduct(string Name,double Price): Product(Name,Price){}
    void getPrice()const{
        cout<<"普通商品"<<name<<"的定价为:"<<price<<endl;
    }

};

class DiscountProduct:public Product{
private:
    double rate;
public:
    DiscountProduct(string Name,double Price,double Rate): Product(Name,Price),rate(Rate){}
    void getPrice()const{
        cout<<"特价商品"<<name<<"的价格为:"<<price*rate<<endl;
    }
};

int main(){
    NormalProduct banana("香蕉",3);
    DiscountProduct apple("苹果",5,0.8);
    banana.getPrice();
    apple.getPrice();
}