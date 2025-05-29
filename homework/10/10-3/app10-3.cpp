#include <iostream>
using namespace std;

// Account 基类
class Account {
public:
    virtual float Deposit(float amount) {
        balance += amount;
        return balance;
    }

    virtual float Withdrawal(float amount) = 0; // 纯虚函数

    unsigned AcntBalance() {
        return balance;
    }

    Account(unsigned accNo, float balan) {
        acntNumber = accNo;
        balance = balan;
    }

    virtual ~Account() {}

protected:
    unsigned acntNumber;
    float balance;

    static int count;
    static Account* pNext;
    static Account* pFirst;
};

// 静态成员初始化
int Account::count = 0;
Account* Account::pNext = nullptr;
Account* Account::pFirst = nullptr;

// Saving 派生类
class Saving : public Account {
public:
    float Withdrawal(float amount) {
        if (balance < amount) {
            cout << "Insufficient funds: balance = " << balance << endl;
            return balance;
        }
        balance -= amount;
        return balance;
    }

    Saving(unsigned accNo, float balan) : Account(accNo, balan) {}
};

// Remit 枚举类型，移到类外部
enum Remit { remitByPost, remitByCable, other };

// Checking 派生类
class Checking : public Account {
public:
    float Withdrawal(float amount) {
        float temp = amount;
        if (remittance == remitByPost) {
            temp = amount + 30;
        } else if (remittance == remitByCable) {
            temp = amount + 60;
        }

        if (balance < temp) {
            cout << "Insufficient funds: balance = " << balance << endl;
            return balance;
        }

        balance -= temp;
        return balance;
    }

    void SetRemit(Remit re) {
        remittance = re;
    }

    Checking(unsigned accNo, float balan) : Account(accNo, balan) {
        remittance = other;
    }

private:
    Remit remittance;
};

// 通过基类指针实现多态的函数
void processAccount(Account* acc) {
    cout << "处理账户：" << endl;
    cout << "存款 100：余额 = " << acc->Deposit(100) << endl;
    cout << "取款 50：余额 = " << acc->Withdrawal(50) << endl;
    cout << endl;
}

int main() {
    // 创建 Saving 和 Checking 对象，使用基类指针
    Account* acc1 = new Saving(101, 1000);
    Account* acc2 = new Checking(201, 2000);

    // 多态调用
    cout << "=== Saving 账户 ===" << endl;
    processAccount(acc1);

    cout << "=== Checking 账户 ===" << endl;
    processAccount(acc2);

    // 释放内存
    delete acc1;
    delete acc2;

    return 0;
}