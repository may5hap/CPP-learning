#include<iostream>
#include<typeinfo>
using namespace std;

class Base{};

class Derive:public Base{};

class Base1{
public:
    virtual void f1(){
    }
};

class Derive1:public Base1{
public:
    void f1(){}
};

int main(){
    //static_cast用于基本数据类型的转换
    int a = 10;
    float f;
    f = static_cast<float>(a);
    cout<<"f:"<<f<<" a:"<<a<<endl;
    //static_cast用于上行转换（指针或引用）
    Base * b = new Base();
    Derive* d = new Derive();
    b = static_cast<Base*>(d);
    cout<<"d:"<<d<<" b:"<<b<<endl;
    //static_cast用于下行转换有风险
    //d = static_cast<Derive*>(b);
    //cout<<"d:"<<d<<" b:"<<b<<endl;
    
    //dynamic_cast不可以用于基本类型转换
    //dynamic_cast多用于类的下行转换（指针或引用），如果转换失败则返回NULL，要求：基类必须要有虚函数，即必须要形成多态
    Base1 * b1 = new Base1();
    Base1* b2 = new Derive1();          //父类指针指向子类对象
    Derive1 * d1 = new Derive1();
    d1 = dynamic_cast<Derive1*>(b1);    //转换失败，因为d1和b1指向类型不一致，d1指向的是Derive类型，b1指向的是Base类型
    if(d1==NULL){
        cout<<"NULL"<<endl;
    }
    else{
        cout<<"d1:"<<d1<<" b1:"<<b1<<endl;
    }

    //转换成功，b2和d1指向的对象都是Derive1类型，只有类型一致才能转换成功
    //注意：dynamic_cast是在运行时进行类型检查，而其他的强制类型转换函数（模版）是在编译时完成
    d1 = new Derive1();
    d1 = dynamic_cast<Derive1*>(b2);
    if(d1==NULL){
        cout<<"NULL"<<endl;
    }
    else{
        cout<<"d1:"<<d1<<" b2:"<<b2<<endl;
    }

    //const_cast，将常量指针和常量引用转换为非常量指针和非常量引用
    const int * n;
    const float * m;
    int * nn = const_cast<int*>(n);
    cout<<"nn:"<<nn<<" n:"<<n<<endl;
    if(typeid(n)==typeid(const int*)) cout<<"type(n):const int*"<<endl;
    //所以说，实际上，n还是const int * 类型，nn是int * 类型，nn指向n所指向的对象，即nn和n指向同一个对象

    /*output：
        f:10 a:10
        d:0x130e06800 b:0x130e06800
        NULL
        d1:0x130e06820 b2:0x130e06820
        nn:0x0 n:0x0
        type(n):const int*
    */
    return 0;
}