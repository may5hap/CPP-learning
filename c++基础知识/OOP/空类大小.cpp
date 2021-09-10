#include<iostream>

class Base{
public:
    // int a;
    // Base(int _a):a(_a){}
    // virtual void Print(){
    //     std::cout << "Base print" << std::endl;
    // }
};

class Derived : public Base{
public:
    // Derived(){}
    void Print(){
        std::cout << "Derived print" << std::endl;
    }
};

int main(){
    Base *b = new Base();
    Base *d = new Derived();
    Base *b1 = new Derived();
    // b->Print();
    // d->Print();
    // b1->Print();
    std::cout << sizeof(Base) << std::endl;

    // 如果是空类，则sizeof(Base)为1，如果包含一个虚函数，则大小为8字节（64位操作系统）
    // 因为此时对象包含一个虚表指针，指向虚函数，指针大小为8字节（64位操作系统）
    return 0;
}