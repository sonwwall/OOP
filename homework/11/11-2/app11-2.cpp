//
// Created by 瑞彤 on 2025/5/29.
//

#include <iostream>
#include <stdexcept>  // 标准异常类定义在这里

using namespace std;

// 除法函数：如果除数为 0，就抛出异常
int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("除数不能为0");  // 抛出异常对象
    }
    return a / b;
}

int main() {
    int x = 10, y = 0;

    try {
        // 尝试执行可能抛出异常的代码
        int result = divide(x, y);
        cout << "结果是：" << result << endl;
    } catch (const runtime_error& e) {
        // 捕获并处理异常
        cout << "捕获异常：" << e.what() << endl;
    }

    cout << "程序继续执行..." << endl;

    return 0;
}
