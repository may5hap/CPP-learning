#include<iostream>
using namespace std;

//通用类模版
template<class T1, class T2>
class A{
public:
    T1 m1;
    T2 m2;
    void f(){
        cout<< "通用类模版" << (m1<m2) <<endl;
    }
};

//偏特化类模版
template<class T2>
class A<int, T2>{       //在类名后声明特化的类型
public:
    int m1;
    T2 m2;
    void f(){
        cout<< "偏特化类模版" << (m1<m2) <<endl;
    }
};

//全特化类模版
template<>
class A<char, char>{    //在类名后声明特化的类型
public:
    char m1;
    char m2;
    void f(){
        cout<< "全特化类模版" << (m1<m2) <<endl;
    }
};

int main(){
    //通用类模版
    A<double,int> a;
    a.m1 = 1.2;
    a.m2 = 2;
    a.f();
    
    //特化类模版
    A<int, double> b;
    b.m1 = 1;
    b.m2 = 2.1;
    b.f();

    //全特化类模版
    A<char, char> c;
    c.m1 = 'a';
    c.m2 = 'b';
    c.f();
    return 0;
}