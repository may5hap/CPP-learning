#include<iostream>
using namespace std;

class Base{
public:
    Base(){
        cout << "基类构造函数调用" << endl;
    }
    virtual ~Base(){            // 需要申明为virtual，否则析构子类对象的时候，会直接调用基类的析构函数，造成内存泄漏
        cout << "基类析构函数调用" << endl;
    }
};

class Derived : public Base{
public:
    Derived(){
        cout << "子类构造函数调用" << endl;
    }
    ~Derived(){
        cout << "子类析构函数调用" << endl;
    }
};

int main(){
    Base * b1 = new Derived();
    delete b1;
    Base * b2 = new Base();
    delete b2;
    Derived * d1 = new Derived();
    delete b2;
    return 0;
}