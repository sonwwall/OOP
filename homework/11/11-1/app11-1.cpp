//
// Created by 瑞彤 on 2025/5/29.
//

#include <iostream>
using namespace std;

class Vector;  // 提前声明

// ------------------ Matrix 类 ------------------
class Matrix {
private:
    int m, n;
    int* Mat;

public:
    Matrix(int im, int in) : m(im), n(in) {
        Mat = new int[m * n];
        for (int i = 0; i < m * n; ++i) Mat[i] = 0;
    }

    ~Matrix() {
        delete[] Mat;
    }

    // 拷贝构造
    Matrix(const Matrix& other) : m(other.m), n(other.n) {
        Mat = new int[m * n];
        for (int i = 0; i < m * n; ++i) Mat[i] = other.Mat[i];
    }

    // 设置某个元素
    int& Elem(int i, int j) {
        return Mat[i * n + j];
    }

    void print() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << Elem(i, j) << " ";
            }
            cout << endl;
        }
    }

    int getM() { return m; }
    int getN() { return n; }

    // 成员函数方式（方式二）
    // 声明为 Vector 的友元函数
    Vector Multiply(Vector& vec);

    // 用户自定义函数方式（方式一）
    friend Vector Multiply(Matrix& mat, Vector& vec);

    // 友元类方式（方式三）
    friend class Vector;
};

// ------------------ Vector 类 ------------------
class Vector {
private:
    int n;
    int* v;

public:
    Vector(int size) : n(size) {
        v = new int[n];
        for (int i = 0; i < n; ++i) v[i] = 0;
    }

    ~Vector() {
        delete[] v;
    }

    Vector(const Vector& other) : n(other.n) {
        v = new int[n];
        for (int i = 0; i < n; ++i) v[i] = other.v[i];
    }

    int& Elem(int i) {
        return v[i];
    }

    int getN() { return n; }

    void print() {
        for (int i = 0; i < n; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    // 方式二：将 Matrix 成员函数设为友元
    friend Vector Matrix::Multiply(Vector& vec);

    // 方式一：全局 Multiply 是友元函数
    friend Vector Multiply(Matrix& mat, Vector& vec);

    // 方式三：整个类是 Matrix 的友元类
    friend class Matrix;
};

// ------------------ Multiply (方式一) ------------------
Vector Multiply(Matrix& mat, Vector& vec) {
    int m = mat.getM();
    int n = mat.getN();
    Vector result(m);

    for (int i = 0; i < m; ++i) {
        result.Elem(i) = 0;
        for (int j = 0; j < n; ++j) {
            result.Elem(i) += mat.Elem(i, j) * vec.Elem(j);
        }
    }
    return result;
}

// ------------------ Multiply 成员函数 (方式二) ------------------
Vector Matrix::Multiply(Vector& vec) {
    Vector result(m);
    for (int i = 0; i < m; ++i) {
        result.v[i] = 0;
        for (int j = 0; j < n; ++j) {
            result.v[i] += Mat[i * n + j] * vec.v[j];
        }
    }
    return result;
}

// ------------------ 主函数 ------------------
int main() {
    Matrix mat(2, 3);  // 2x3矩阵
    Vector vec(3);     // 长度为3的向量

    // 初始化矩阵
    mat.Elem(0, 0) = 1; mat.Elem(0, 1) = 2; mat.Elem(0, 2) = 3;
    mat.Elem(1, 0) = 4; mat.Elem(1, 1) = 5; mat.Elem(1, 2) = 6;

    // 初始化向量
    vec.Elem(0) = 1;
    vec.Elem(1) = 2;
    vec.Elem(2) = 3;

    cout << "Matrix:" << endl;
    mat.print();

    cout << "Vector:" << endl;
    vec.print();

    cout << "Result of Multiply (方式一):" << endl;
    Vector result1 = Multiply(mat, vec);
    result1.print();

    cout << "Result of Multiply (方式二):" << endl;
    Vector result2 = mat.Multiply(vec);
    result2.print();

    cout << "Result of Multiply (方式三):" << endl;
    // 方式三的 Multiply 可以直接在 Matrix 内实现，这里与方式二等效

    return 0;
}
