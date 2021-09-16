#include<iostream>

using namespace std;

struct data{
    int a;
    short b;
    char c;
};

struct data1{
    int a;
    char b;
    char c;
    double d;
};

struct data2{
    char a;
    int b;
    char c;
    double d;
};

struct A
{
    char a1;
    short int a2;
    int a3;
    double d;
};

int main(){
    struct data d;
    cout << &(d.a) << endl;
    cout << &(d.b) << endl;
    cout << &(d.c) << endl;

    struct data1 d1;
    cout << &(d1.a) << endl;
    cout << &(d1.b) << endl;
    cout << &(d1.c) << endl;
    cout << &(d1.d) << endl;

    cout << sizeof(data) << endl;
    cout << sizeof(data1) << endl;
    cout << sizeof(data2) << endl;
    cout << sizeof(A) << endl;

    struct data2 d2;
    cout << &(d2.a) << endl;
    cout << &(d2.b) << endl;
    cout << &(d2.c) << endl;
    cout << &(d2.d) << endl;

    cout << sizeof(double) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(long) << endl;   // long 在64为linux下占8字节
    cout << sizeof(int) << endl;
    return 0;
}

// 还是没弄明白