#include<iostream>

using namespace std;

struct data{
    int a;
    short b;
    char c;
};

struct data1{
<<<<<<< HEAD
    char a;
    long b;
=======
    int a;
    char b;
    char c;
    double d;
};

struct data2{
    char a;
    int b;
>>>>>>> bb5f5b5e24c74e5e4050f902c3cd18b6f591fbf5
    char c;
    double d;
};

<<<<<<< HEAD
=======
struct A
{
    char a1;
    short int a2;
    int a3;
    double d;
};

>>>>>>> bb5f5b5e24c74e5e4050f902c3cd18b6f591fbf5
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
<<<<<<< HEAD
    cout << sizeof(double) << endl;
=======
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
>>>>>>> bb5f5b5e24c74e5e4050f902c3cd18b6f591fbf5
    return 0;
}

// 还是没弄明白