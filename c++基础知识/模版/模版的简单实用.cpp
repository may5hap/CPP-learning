#include<iostream>
using namespace std;

//1、函数模版
template<class T>
T add(T& a, T& b){
    return a+b;
}

//2、类模版
template<class T>
class Complex{
public:
    T real;
    T imag;
    Complex(T a, T b):real(a),imag(b){}
    Complex<T> operator+(Complex<T>& a){
    //重载运算符+，这里参数列表和返回值以后下面这一行中的T都可以删除
    //是c++17的一个特性，类模版
        Complex<T> tmp(this->real+a.real,this->imag+a.imag);
        cout<<tmp.real<<"   "<<tmp.imag<<endl;
        return tmp;
    }
};

int main(){
    //函数模版测试
    int a = 10, b = 20;
    cout<<add<int>(a,b)<<endl;
    double c = 2.4, d = 9.2;
    cout<<add(c,d)<<endl;   //函数模版可以自动类型推导
    
    //类模版测试
    Complex<int> instance1(1,2);
    Complex<int> instance2(10,20);
    Complex<int> instance3=instance2+instance1;
    return 0;
}