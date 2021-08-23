#include<iostream>

using namespace std;

class A{
public:
    int val1,val2;
    A(int _val1,int _val2):val1(_val1),val2(_val2){}
    int add(){
        return val1+val2;
    }
    void test(){
        A a(1,2);
        //this = &a;    //错误，this是指针常量，不能修改其值
        *this = a;      //正确，可以修改this所指的内容，this是指向当前对象的指针
        cout<<this->val1<<endl;
        cout<<this->val2<<endl;
    }
};

int main(){
    A a1(10,20);
    int *p = &a1.val1;
    cout<<*p<<endl;
    int (A::*fun_p)();  //这里需要带上类的空间，表明此函数指针是指向该类下的一个函数的
    //fun_p = A::add;   //错误，需要加取地址符号
    fun_p = &A::add;
    cout<<(a1.*fun_p)()<<endl;  //类成员函数的调用，需要用类对象.函数

    void (A::*fun_p2)();
    fun_p2 = &A::test;
    (a1.*fun_p2)();
    return 0;
}